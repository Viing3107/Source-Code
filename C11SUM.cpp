# include <bits/stdc++.h>
# define int long long
# define task "test"
# pragma GCC optimize("O2", "O3", "Ofast")
# pragma target("avx", "avx2", "fma")

using namespace std;

const int MOD = 1e9 + 7;
string s;
int tmp, res, n;

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> s;
}

void init(){
	n = s.size();
	s = " " + s;
	res = tmp = 0;
}

void solve(){
	for (int i = 1; i <= n; i++){
		tmp = (10 * tmp + i * (s[i] - '0')) % MOD;
		res = (res + tmp) % MOD;
	}
}

void output(){
	cout << res << endl;
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

	return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/c11sum