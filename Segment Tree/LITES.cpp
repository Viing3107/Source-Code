# include <bits/stdc++.h>
# define int long long

using namespace std;

const int N = 1e5 + 5;
int n, m, st[4 * N], lazy[4 * N], type, s, e;

void update(int id, int l, int r, int u, int v){
	if (r < u || l > v) return;
	if (u <= l && r <= v){
		lazy[id] ^= 1;
		st[id] = r - l + 1 - st[id];
		return;
	}
	int m = (l + r) / 2;
	update(id * 2, l, m, u, v);
	update(id * 2 + 1, m + 1, r, u, v);
	st[id] = st[id * 2] + st[id * 2 + 1];
	if (lazy[id]) st[id] = r - l + 1 - st[id];
}

int get(int id, int l, int r, int u, int v){
	if (r < u || l > v) return 0;
	if (u <= l && r <= v) return st[id];
	int m = (l + r) / 2;
	int t1 = get(id * 2, l, m, u, v);
	int t2 = get(id * 2 + 1, m + 1, r, u, v);
	int res = t1 + t2;
	if (lazy[id]) return min(r, v) - max(l, u) + 1 - res;
	return res;
}

void input(){
	cin >> n >> m; 
}

void solve(){
	while (m--){
		cin >> type >> s >> e;
		if (type) cout << get(1, 1, n, s, e) << endl;
		else update(1, 1, n, s, e);
	}
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	input();
	solve();
	
	return 0;
}

// https://oj.vnoi.info/problem/lites
