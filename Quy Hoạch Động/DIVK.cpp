# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll INF = 1e6 + 6, N = 1e6 + 6;
ll n, k, a[N], res, s, dp[1111][55];
// dp[i][j] : chọn ra ít nhất dp[i][j] phần tử trong đoạn a[1..i] để có tổng chia k dư j

int main(){
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		s += a[i];
		s %= k;
	}
	dp[0][0] = 0;
	for (int i = 1; i < k; i++) dp[0][i] = INF;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < k; j++) dp[i][j] = min(dp[i - 1][j], dp[i - 1][((j - a[i]) % k + k) % k] + 1);
	}
	cout << n - dp[n][s % k] << endl;
	
	return 0;
}

// https://oj.vnoi.info/problem/QBSEQ
