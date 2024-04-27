# include <bits/stdc++.h>
# define ll long long
# define endl "\n"

using namespace std;

const ll N = 1e5 + 5;
ll n, q, a[N], sum, st[4 * N];

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

ll get(int id, int l, int r, int u, int v){
	if (r < u || l > v) return 0;
	if (u <= l && r <= v) return st[id];
	int m = (l + r) / 2;
	ll temp1 = get(id * 2, l, m, u, v);
	ll temp2 = get(id * 2 + 1, m + 1, r, u, v);
	return temp1 + temp2;
}

int main(){
	
	cin >> n >> q;
	while (q--){
		int type, x, y;
		cin >> type >> x >> y;
		if (type == 1) update(1, 1, n, x, y);
		else cout << get(1, 1, n, x, y) << endl;
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/segtree_itez2

