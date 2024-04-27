# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 5e5 + 5;
ll n, t, a[N], l, r, st[4 * N];

void build(int id, int l, int r){
	if (l == r){
		st[id] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	st[id] = max(st[id * 2], st[id * 2 + 1]);
}

ll get(int id, int l, int r, int u, int v){
	if (r < u || l > v) return -1e9;
	if (u <= l && r <= v) return st[id];
	int m = (l + r) / 2;
	ll t1 = get(id * 2, l, m, u, v);
	ll t2 = get(id * 2 + 1, m + 1, r, u, v);
	return max(t1, t2);
}

int main(){
	
	cin >> n >> t;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	while (t--){
		cin >> l >> r;
		cout << get(1, 1, n, l, r) << endl;
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/fc072_seq13
