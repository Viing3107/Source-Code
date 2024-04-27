# include <bits/stdc++.h>
# define int long long
# define endl "\n"

using namespace std;

const int N = 1e5 + 5;
int n, q, a[N], st[4 * N], t1, t2, type, u, v;

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
		st[id] = a[index] = value;
		return;
	}
	int m = (l + r) / 2;
	update(id * 2, l, m, index, value);
	update(id * 2 + 1, m + 1, r, index, value);
	st[id] = st[id * 2] + st[id * 2 + 1];
}

int getSum(int id, int l, int r, int u, int v){
	if (r < u || l > v) return 0;
	if (u <= l && r <= v) return st[id];
	int m = (l + r) / 2;
	int t1 = getSum(id * 2, l, m, u, v);
	int t2 = getSum(id * 2 + 1, m + 1, r, u, v);
	return t1 + t2;
}

void input(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
}

void init(){
	build(1, 1, n);
}

void solve(){
	while (q--){
		cin >> type >> u >> v;
		if (type) cout << getSum(1, 1, n, u, v) << endl;
		else{
			t1 = a[u];
			t2 = a[v];
			update(1, 1, n, u, t2);
			update(1, 1, n, v, t1);
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	input();
	init();
	solve();
	
	return 0;
}

// https://oj.vnoi.info/problem/fc109_swap
