# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# define name "test"

using namespace std;

const int N = 120;
int t, n, k;
map<int, int> mp;

int f(int n){
	if (mp.count(n)) return mp[n];
	int k = n / 2;
	if (n % 2) return mp[n] = f(k) * f(k + 1) + f(k - 1) * f(k);
	return mp[n] = f(k - 1) * f(k - 1) + f(k) * f(k);
}

void input(){
	# ifndef ONLINE_JUDGE
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	# endif
}

void init(){
	mp[0] = mp[1] = 1;
}

void solve(){
	cin >> t;
	while (t--){
		cin >> n >> k;
		if (n > 93) cout << "no\n";
		else{
			if (f(n - 1) > k) cout << "no\n";
			else cout << "yes\n";
		}
	}
}

void output(){
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

// https://oj.vnoi.info/problem/bedao_m08_triangle