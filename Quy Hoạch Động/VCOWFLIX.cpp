# include <bits/stdc++.h>
# define ll long long

using namespace std;

int c, n, w[22], dp[22][5555];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> c >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= c; j++){
			dp[i][j] = dp[i - 1][j];
			if (j >= w[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + w[i]);
		}
	}
	cout << dp[n][c] << endl;
	
	return 0;
}

// https://oj.vnoi.info/problem/vcowflix
// bai knapsack nhma la phien ban nhai :))
