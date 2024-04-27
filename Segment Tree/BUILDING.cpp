# include <bits/stdc++.h>
# define int long long
# define task "test"
# pragma GCC optimize("O2", "O3", "Ofast")
# pragma target("avx", "avx2", "fma")

using namespace std;

const int N = 1e5 + 5;
int n, q, h[N], a[N], st[4 * N], type, pos, value, l, r, x;

void build(int id, int l, int r){
	if (l == r){
		st[id] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	st[id] = st[id * 2] + st[id * 2 + 1];
}

void update(int id, int l, int r, int index, int value){
	if (index < l || index > r) return;
	if (l == r){
		h[index] = value;
		a[index] = abs(h[index] - h[index - 1]);
		st[id] = a[index];
		return;
	}
	int m = (l + r) / 2;
	update(id * 2, l, m, index, value);
	update(id * 2 +  1, m + 1, r, index, value);
	st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v){
	if (r < u || l > v) return 0;
	if (u <= l && r <= v) return st[id];
	int m = (l + r) / 2;
	int t1 = get(id * 2, l, m, u, v);
	int t2 = get(id * 2 + 1, m + 1, r, u, v);
	return t1 + t2;
}

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	cin >> q;
}

void init(){
	for (int i = 1; i <= n; i++) a[i] = abs(h[i] - h[i - 1]);
	build(1, 1, n);
}

void solve(){
	while (q--){
		cin >> type >> l >> r;
		if (type == 1){
			update(1, 1, n, l, r);
			update(1, 1, n, l + 1, h[l + 1]);
		}
		else cout << get(1, 1, n, l + 1, r) << endl;
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

// https://oj.vnoi.info/problem/bedao_m05_building