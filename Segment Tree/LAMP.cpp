# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# define gcd(a, b) __gcd(a, b)

using namespace std;

const int N = 1e5 + 5;
int n, q, u, v, cnt, a[N], st[4 * N], lazy[4 * N], res;

void update(int id, int l, int r, int u, int v){
	if (r < u || l > v) return;
	if (u <= l && r <= v){
		lazy[id] ^= 1;
		st[id] ^= 1;
		return;
	}
	int m = (l + r) / 2;
	update(id * 2, l, m, u, v);
	update(id * 2 + 1, m + 1, r, u, v);
	st[id] = st[id * 2] ^ st[id * 2 + 1] ^ lazy[id];
}

int get(int id, int l, int r, int pos){
	if (pos < l || pos > r) return 0;
	if (l == r) return st[id];
	int m = (l + r) / 2;
	int t1 = get(id * 2, l, m, pos);
	int t2 = get(id * 2 + 1, m + 1, r, pos);
	return t1 ^ t2 ^ lazy[id];
}

void input(){
	cin >> n >> q;
}

void solve(){
	while (q--){
		cin >> u >> v;
		update(1, 1, n, u, v);
	}
}

void output(){
	for (int i = 1; i <= n; i++) cout << get(1, 1, n, i) << " ";
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	input();
	solve();
	output();
	
	return 0;
}

// https://oj.vnoi.info/problem/fc051_lamp
