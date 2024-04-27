# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# define name "test"

using namespace std;

const int N = 1e2 + 2;
int n, a[N], b[N][N];

void input(){
	# ifndef ONLINE_JUDGE
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	# endif
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
}

void init(){
}

void solve(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			b[i][j] = a[i] ^ a[j];
			cout << b[i][j] << " ";
		}
		cout << endl;
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

// https://oj.vnoi.info/problem/fct020_xortable