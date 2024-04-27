# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# pragma GCC optinization("Ofast")
# define name "test"
# define gcd(a, b) __gcd(a, b)
# define lcm(a, b) a / gcd(a, b) * b
# define TR(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N = 1e5 + 5;
int l[4], c[4], n, first, last, a[N], dp[N], ind;

string to_string(int n){
	string res;
	stringstream ss;
	ss << n;
	res = ss.str();
	return res;
}

int stolli(string s){
	int res;
	stringstream ss(s);
	ss >> res;
	return res;
}

void input(){
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	cin >> l[1] >> l[2] >> l[3] >> c[1] >> c[2] >> c[3] >> n >> first >> last;
	for (int i = 2; i <= n; i++) cin >> a[i];
}

void init(){
	dp[first] = 0;
}

void solve(){
	for (int i = first + 1; i <= last; i++){
		dp[i] = 1e18;
		for (int j = 1; j <= 3; j++){
			ind = lower_bound(a + first, a + i, a[i] - l[j]) - a;
			dp[i] = min(dp[i], dp[ind] + c[j]);
		}
	}
}

void output(){
	cout << dp[last] << endl;
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

	return 0;
}

// https://oj.vnoi.info/problem/qbticket