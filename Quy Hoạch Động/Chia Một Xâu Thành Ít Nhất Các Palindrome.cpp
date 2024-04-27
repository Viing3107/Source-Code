# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# pragma GCC optimize("O2")
# define name "test"
# define gcd(a, b) __gcd(a, b)

using namespace std;

const int N = 256;
int n, m, isPalin[N][N], dp[N], trace[N];
string s;

void input(){
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	cin >> s;
}

void init(){
	n = s.size();
	s = " " + s;
	for (int i = 1; i <= n; i++) isPalin[i][i] = isPalin[i + 1][i] = 1;
	// kiểm tra palindrome
	for (int i = n; i >= 1; i--)
		for (int j = i + 1; j <= n; j++) isPalin[i][j] = s[i] == s[j] && isPalin[i + 1][j - 1];
}

void solve(){
	for (int i = 1; i <= n; i++){
		dp[i] = n;
		for (int j = i - 1; j >= 0; j--){
			if (isPalin[j + 1][i] && dp[i] > dp[j] + 1){
				dp[i] = dp[j] + 1;
				trace[i] = j + 1;  // đánh dấu truy vết
			}
		}
	}
	cout << dp[n] << endl;
	// truy vết
	vector<string> ans;
    for (int i = n; i; i = trace[i] - 1) {
        string palin = "";
        for (int j = trace[i]; j <= i; j++) palin += s[j];
        ans.push_back(palin);
    }
    reverse(ans.begin(), ans.end());
    for(auto it : ans) cout << it << endl;
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

	return(0);
}

// https://oj.vnoi.info/problem/countpl