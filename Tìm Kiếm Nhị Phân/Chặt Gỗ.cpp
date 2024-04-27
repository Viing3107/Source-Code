# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# pragma GCC optinization("Ofast")
# define name "wood"
# define gcd(a, b) __gcd(a, b)
# define lcm(a, b) a / gcd(a, b) * b
# define TR(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N = 1e6 + 6;
int n, M, a[N], l, r, m, h, res;

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
int f(int m){
	int res = 0;
	for (int i = 1; i <= n; i++) res += max(0ll, a[i] - m);
	return res;
}

void input(){
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	cin >> n >> M;
	for (int i = 1; i <= n; i++) cin >> a[i];
}

void init(){
	l = 0;
	r = 2e9;
}

void solve(){
	while (r - l >= 0){
		m = (l + r) / 2;
		if (f(m) >= M){
			res = m;
			l = m + 1;
		}
		else r = m - 1;
	}
}

void output(){
	cout << res;
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

// http://www.spoj.com/PTIT/problems/PTIT126J/