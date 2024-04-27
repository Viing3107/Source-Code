# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 1e4 + 4;
ll dp[N], n, k, res, a[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[1] = a[1];
	for (int i = 2; i <= n; i++){
		res = -1e9;
		for (int j = 1; j <= k; j++){
			if (i - j >= 0) res = max(res, dp[i - j] + a[i]);
			else break;
		}
		dp[i] = res;
	}
	res = -1e9;
	for (int i = 1; i <= n; i++) res = max(res, dp[i]);
	cout << res << endl;
	
	return 0;
}

// https://oj.vnoi.info/problem/amsseq
