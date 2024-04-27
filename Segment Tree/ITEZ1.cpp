# include <bits/stdc++.h>
# define ll long long 
# define endl "\n"

using namespace std;

const ll N = 1e5 + 5;
ll n, a[N], st[4 * N], q, type, u, v;

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

void update(int id, int l, int r, int index, int value){
	if (index < l || index > r) return;
	if (l == r){
		st[id] = a[index] = value;
		return;
	}
	int m = (l + r) / 2;
	update(id * 2, l, m, index, value);
	update(id * 2 + 1, m + 1, r, index, value);
	st[id] = max(st[id * 2], st[id * 2 + 1]);
}

ll get(int id, int l, int r, int u, int v){
	if (r < u || l > v) return -1e9;
	if (u <= l && r <= v) return st[id];
	int m = (l + r) / 2;
	ll temp1 = get(id * 2, l, m, u, v);
	ll temp2 = get(id * 2 + 1, m + 1, r, u, v);
	return max(temp1, temp2);
}

int main(){
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	cin >> q;
	while (q--){
		cin >> type >> u >> v;
		if (type == 1) update(1, 1, n, u, v);
		else cout << get(1, 1, n, u, v) << endl;
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/segtree_itez1
