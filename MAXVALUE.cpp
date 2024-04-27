# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# define name "test"

using namespace std;

const int N = 1e7 + 7;
int t, n, m, k, x, q, a[N], preMax[N], sufMax[N], best, l, r, d;

void input(){
	# ifndef ONLINE_JUDGE
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	# endif
	cin >> n >> m >> k >> x >> q;
}

void init(){
	a[1] = x;
	for (int i = 2; i <= n; i++) a[i] = (a[i - 1] * k) % m;
	for (int i = 1; i <= n; i++) a[i] -= q;
	preMax[0] = -1e18;
	for (int i = 1; i <= n; i++) preMax[i] = max(preMax[i - 1], a[i]);
	sufMax[n + 1] = -1e18;
	for (int i = n; i >= 1; i--) sufMax[i] = max(sufMax[i + 1], a[i]);
	best = *max_element(a + 1, a + n + 1);
}

void solve(){
	cin >> t;
	while (t--){
		cin >> l >> r >> d;
		if (max(preMax[l - 1], sufMax[r + 1]) == best) cout << best << endl;
		else cout << max({preMax[l - 1], best - d, sufMax[r + 1]}) << endl;
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

	return 0;
}

// https://oj.vnoi.info/problem/hello22_maxval