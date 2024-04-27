# include <bits/stdc++.h>
# define int long long

using namespace std;

const int MOD = 1e9 + 7;
int a, n, x, y;

int binPow(int a, int b){
	int res = 1;
	while(b){
		if(b & 1) res = (res * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if (fopen("test.inp", "r")){
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}

	cin >> a >> n;
	x = ((binPow(a, n + 1) - 1) % MOD + MOD) % MOD;
	y = binPow(a - 1, MOD - 2) % MOD;
	cout << (x * y) % MOD;

	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

	return 0;
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/fc069_calsum