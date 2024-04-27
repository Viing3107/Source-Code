# include <bits/stdc++.h>
using namespace std;
const long long N = 222222;
int n, k, h[N], dp[N], temp;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) cin >> h[i];
	dp[1] = 0;
	for (int i = 2; i <= n; i ++) {
		temp = 1e9;
		for (int j = 1; j <= k; j ++) 
			if (i - j >= 1) temp = min(temp, dp[i - j] + abs(h[i] - h[i - j]));
		dp[i] = temp;
	}
	cout << dp[n];
	
	return 0;
}

// https://oj.vnoi.info/problem/atcoder_dp_b
