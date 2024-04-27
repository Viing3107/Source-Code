# include <bits/stdc++.h>
# define int long long
# define endl "\n"

using namespace std;

const int N = 1e5 + 5;
int n, m, a[N], type, l, r, k, i, value;
multiset<int> st[4 * N];

void build(int id, int l, int r){
	if (l == r){
		st[id].insert(a[l]);
		return;
	}
	int m = (l + r) / 2;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	st[id] = st[id * 2];
	for (auto it : st[id * 2 + 1]) st[id].insert(it);
}

void update(int id, int l, int r, int index, int value_old, int value_new){
	if (index < l || index > r) return;
	if (l == r){
		st[id].clear();
		st[id].insert(value_new);
		a[index] = value_new;
		return;
	}
	int m = (l + r) / 2;
	update(id * 2, l, m, index, value_old, value_new);
	update(id * 2 + 1, m + 1, r, index, value_old, value_new);
	st[id].erase(st[id].find(value_old));
	st[id].insert(value_new);
}

int get(int id, int l, int r, int u, int v, int k){
	if (r < u || l > v) return 1e9;
	if (u <= l && r <= v){
		auto it = st[id].lower_bound(k);
		if (it == st[id].end()) return 1e9;
		else return *it;
	}
	int m = (l + r) / 2;
	int t1 = get(id * 2, l, m, u , v, k);
	int t2 = get(id * 2 + 1, m + 1, r, u, v, k);
	return min(t1, t2);
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	while (m--){
		cin >> type;
		if (type == 1){
			cin >> i >> value;
			update(1, 1, n, i, a[i], value);
		}
		else{
			cin >> l >> r >> k;
			int ans = get(1, 1, n, l, r, k);
			if (ans == 1e9) cout << -1 << endl;
			else cout << ans << endl;
		}
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/segtree_itds1
