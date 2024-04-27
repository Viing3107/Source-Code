# include <bits/stdc++.h>
# define int long long
# define task "rdat"
# pragma GCC optimize ("O2", "O3", "Ofast")
# pragma target ("avx", "avx2", "fma") 

using namespace std;
mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r){
    return l + (rng() * rng() % (r - l + 1) + (r - l + 1)) % (r - l + 1);
}

const int N = 1e5 + 5;
int n, q, a[N], u, v, l, r;
multiset<int, greater<int>> st[4 * N], res, tmp;

multiset<int, greater<int>> Merge(multiset<int, greater<int>> a, multiset<int, greater<int>> b){
	multiset<int, greater<int>> res;
	for(typeof(a.begin()) it = a.begin(); it!= a.end(); it++) res.insert(*it);
	for(typeof(b.begin()) it = b.begin(); it!= b.end(); it++) res.insert(*it);
	return res;
}

void build(int id, int l, int r){
	if (l == r){
		st[id].insert(a[l]);
		return;
	}
	int m = (l + r) / 2;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	st[id] = Merge(st[id * 2], st[id * 2 + 1]);
}

multiset<int, greater<int>> get(int id, int l, int r, int u, int v){
	if (r < u || l > v) return tmp;
	if (u <= l && r <= v) return st[id];
	int m = (l + r) / 2;
	multiset<int, greater<int>> t1 = get(id * 2, l, m, u, v);
	multiset<int, greater<int>> t2 = get(id * 2 + 1, m + 1, r, u, v);
	return Merge(t1, t2);
}

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
}

void init(){
	build(1, 1, n);
}

void solve(){
	while (q--){
		cin >> l >> r;
		res = get(1, 1, n, l, r);
		u = 0;
		v = 2;
		for (typeof(res.begin()) it = res.begin(); it != res.end() && v--; it++) u += *it;
		cout << u << endl;
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

// E :\Khối 10 Duyên Hải 2023\Khoi10_DuyenHai2023.pdf