# include <bits/stdc++.h>
# define endl "\n"
# define ll long long

using namespace std;

const ll N = 1e6 + 6, base = 1e9 + 7;
int q, dp[3][N];
char a[3][N];
string s, t;

int main(){
	
	cin >> q;
	while (q--){
		cin >> s >> t;
		int n = s.size();
		s = "!" + s;
		t = "!" + t;
		for (int i = 1; i <= n; i++) a[1][i] = s[i];
		for (int i = 1; i <= n; i++) a[2][i] = t[i];
		dp[1][1] = (a[1][1] == 'X') ? 1 : 0;
		dp[2][1] = (a[2][1] == 'X') ? 1 : 0;
		for (int j = 2; j <= n; j++){
			dp[1][j] = dp[1][j - 1] % base + dp[2][j - 1] % base;
			dp[1][j] %= base;
			if (a[1][j] == 'O') dp[1][j] = 0;
			dp[2][j] = dp[1][j - 1] % base + dp[2][j - 1] % base;
			dp[2][j] %= base;
			if (a[2][j] == 'O') dp[2][j] = 0;
		}
		cout << (dp[1][n] + dp[2][n]) % base << endl;
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/olp_ct21_bridge
