# include <bits/stdc++.h>
# define ll long long

using namespace std;

long long dp[3333][3333], n, m;
string s, t, res;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s >> t;
	n = s.size();
	m = t.size();
	s = " " + s;
	t = " " + t;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	res = "";
	while (n != 0 && m != 0){
		if (s[n] == t[m]){
			res += s[n];
			m--;
			n--;
		}
		else if (dp[n - 1][m] > dp[n][m - 1]) n--;
		else m--;
	}
	reverse(res.begin(), res.end());
	cout << res << endl;
	
	return 0;
}

// https://oj.vnoi.info/problem/atcoder_dp_f
