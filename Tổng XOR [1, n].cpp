# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# define name "test"
# pragma GCC optimize("Ofast")
# pragma GCC target("avx,avx2,fma")

using namespace std;

int t, l, r;

int XOR(int n){
	if (n % 4 == 0) return n;
	if (n % 4 == 1) return 1;
	if (n % 4 == 2) return n + 1;
	return 0;
}

void input(){
	# ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	# endif
}

void init(){
}

void solve(){
	cin >> t;
	while (t--){
		cin >> l >> r;
		cout << (XOR(r) ^ XOR(l - 1)) << endl;
	}
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

	return 0;
}

// https://oj.vnoi.info/problem/bedao_r14_sumxor