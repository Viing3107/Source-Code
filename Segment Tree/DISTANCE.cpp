# include <bits/stdc++.h>
# define int long long
# define endl "\n"

using namespace std;

const int N = 1e5 + 5;
int m, n, k, a[N], b[N], st[4 * N];

void build(int id, int l, int r){
	if (l == r){
		st[id] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	st[id] = min(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v){
	if (r < u || l > v) return 1e9;
	if (u <= l && r <= v) return st[id];
	int m = (l + r) / 2;
	int t1 = get(id * 2, l, m, u, v);
	int t2 = get(id * 2 + 1, m + 1, r, u, v);
	return min(t1, t2);
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= m; i++){
		int ind1 = lower_bound(b + 1, b + n + 1, a[i]) - b;
		int ind2 = upper_bound(b + 1, b + n + 1, a[i]) - b;
		int ind3 = max(1ll, ind1 - 1);
		int ind4 = max(1ll, ind2 - 1);
		a[i] = min(abs(a[i] - b[ind1]), min(abs(a[i] - b[ind2]), min(abs(a[i] - b[ind3]), abs(a[i] - b[ind4]))));
	}
	build(1, 1, m);
	while (k--){
		int l, r;
		cin >> l >> r;
		cout << get(1, 1, m, l, r) << endl;
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/olp_kc21_distance
