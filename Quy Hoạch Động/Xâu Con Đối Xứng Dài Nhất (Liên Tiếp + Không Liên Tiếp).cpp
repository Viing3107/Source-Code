# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# define name "substr"

using namespace std;

const int N = 1e4 + 4;
int dp[N][N], n, res;
string s, t;

void input(){
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	getline(cin, s);
}

void init(){
	n = s.size();
	t = s;
	reverse(t.begin(), t.end());
	s = " " + s;
	t = " " + t;
	res = -1e9;
}

void solve(){
	// DP : Xâu Con Đối Xứng (Liên Tiếp) Dài Nhất
	for (int i = 1; i <= n; i++) dp[i][i] = 1;
	for (int length = 2; length <= n; length++){
		for (int i = 1; i <= n - length + 1; i++){
			int j = i + length - 1;
			if (s[i] == s[j]){
				if (length == 2) dp[i][j] = 1;
				else dp[i][j] = dp[i + 1][j - 1];
			}
			if (dp[i][j]) res = max(res, length);
		}
	}
	cout << res << endl;
	// DP : Xâu Con Đối Xứng (Không Liên Tiếp) Dài Nhất
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) dp[i][j] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			if (s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	cout << dp[n][n] << endl;
}

void output(){

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