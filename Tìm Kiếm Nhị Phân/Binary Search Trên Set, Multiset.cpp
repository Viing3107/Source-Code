# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# define name "test"
# define gcd(a, b) __gcd(a, b)
# define lcm(a, b) a / gcd(a, b) * b
# define TR(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N = 1e6 + 6;
int n, m, a[N], b[N], ind;
multiset<int> ms;

void input(){
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
}

void init(){
	for (int i = 1; i <= n; i++) ms.insert(a[i]);
}

void solve(){
	for (int i = 1; i <= m; i++){
		if (ms.empty()) break;
		auto it = ms.upper_bound(b[i]);
		if (it != ms.begin()) ms.erase(--it);
	}
}

void output(){
	if (ms.empty()) cout << -1 << endl;
	else cout << *ms.rbegin() << endl;
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

// https://oj.vnoi.info/problem/bedao_r10_volunteers