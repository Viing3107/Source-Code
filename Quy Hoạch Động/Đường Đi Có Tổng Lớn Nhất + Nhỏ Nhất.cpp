# include <bits/stdc++.h>
# define int long long
# define task "game"

using namespace std;

const int N = 1e3 + 3, LIM = 1e9;
int n, m, a[N][N], dp[N][N], tmp, b, minimum, maximum;

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n >> m >> b;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> a[i][j];
}

void init(){
	minimum = 1e18;
	maximum = -1e18;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) dp[i][j] = LIM;
}

void solve(){
	for (int j = 1; j <= m; j++) dp[1][j] = (a[1][j] == 0 ? b / 2 : b + a[1][j]);
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= m; j++){
			tmp = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1]));
			if (!a[i][j]) dp[i][j] = tmp - tmp / 2;
			else dp[i][j] = tmp + a[i][j];
		}
	}
	for (int j = 1; j <= m; j++) minimum = min(minimum, dp[n][j]);
	cout << minimum << endl;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) dp[i][j] = -LIM;
	for (int j = 1; j <= m; j++) dp[1][j] = (a[1][j] == 0 ? b / 2 : b + a[1][j]);
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= m; j++){
			tmp = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i - 1][j + 1]));
			if (!a[i][j]) dp[i][j] = tmp - tmp / 2;
			else dp[i][j] = tmp + a[i][j];
		}
	}
	for (int j = 1; j <= m; j++) maximum = max(maximum, dp[n][j]);
	cout << maximum << endl;
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

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/