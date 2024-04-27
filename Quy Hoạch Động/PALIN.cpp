# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 5e3 + 3;
ll n, k, dp[N][N];
string s;


int main(){      
	
	cin >> n >> s;
	s = "!" + s;
	for (int i = 1; i <= n; i++) dp[i][i] = 0;
	for (int k = 1; k < n; k++){
		for (int i = 1; i <= n - k; i++){
			int j = i + k;
			if (s[i] == s[j]){
				if (j - i == 1) continue;
				else dp[i][j] = dp[i + 1][j - 1];
			}
			else{
				if (j - i == 1) dp[i][j] = 1;
				else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
			}
		}
	}
	cout << dp[1][n];
	
	
	return 0;
}

// https://oj.vnoi.info/problem/fc028_palin
