# include <bits/stdc++.h>
# define int long long
# define task "test"
# pragma GCC optimize("O2", "O3", "Ofast")
# pragma target("avx", "avx2", "fma")

using namespace std;

const int N = 3e4 + 4;
int n, a[N], q, l, r, x;
vector<int> st[4 * N];

void build(int id, int l, int r){
	if (l == r){
		st[id].push_back(a[l]);
		return;
	}
	int m = (l + r) / 2;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	vector<int> tmp(st[id * 2].size() + st[id * 2 + 1].size());
	st[id] = tmp;  // khởi tạo st[id] là một vector rỗng, có size = st[id * 2].size + st[id * 2 + 1].size, nếu không khởi tạo thì hàm merge sẽ lỗi
	merge(st[id * 2].begin(), st[id * 2].end(), st[id * 2 + 1].begin(), st[id * 2 + 1].end(), st[id].begin());  // hàm được hỗ trợ sẵn
}

int get(int id, int l, int r, int u, int v, int k){
	if (r < u || l > v) return 0;
	if (u <= l && r <= v) return st[id].size() - (upper_bound(st[id].begin(), st[id].end(), k) - st[id].begin());  // tìm số phần tử lớn hơn k
	int m = (l + r) / 2;
	int t1 = get(id * 2, l, m, u, v, k); // số lượng số phần tử thỏa mãn của nút cha bằng hai nut con cộng lại
	int t2 = get(id * 2 + 1, m + 1, r, u, v, k);
	return t1 + t2;
}

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> q;
}

void init(){
	build(1, 1, n);
}

void solve(){
	while (q--){
		cin >> l >> r >> x;
		cout << get(1, 1, n, l, r, x) << endl;
	}
}

void output(){
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	init();
	solve();
	output();

	return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/kquery