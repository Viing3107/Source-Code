# include <bits/stdc++.h>

using namespace std;

string s;
long long dp[120][120], n;

int main() {
	cin >> s;
	n = s.length();
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == j) dp[i][j] = 1;
			else dp[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j + i < n; j++){
			if (s[j] == s[i + j]) dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
			else dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
		}
	}
	cout << dp[0][n - 1];
	return 0;
}

// https://oj.vnoi.info/problem/qbpal