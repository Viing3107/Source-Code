# include <bits/stdc++.h>
# define int long long
# define task "test"
# pragma GCC optimize("O2", "O3", "Ofast")
# pragma target("avx", "avx2", "fma")

using namespace std;

const int MOD = 1e9 + 7;

int a, b;

// Nghịch Đảo Modulo
// Nếu gcd(b, MOD) = 1 : (a / b) % MOD = a % MOD * b ^ (MOD - 2) % MOD

int binaryExponentiation(int a, int b){
	int res = 1;
	for (; b; b >>= 1){
		if (b & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
	}
	return res;
}

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> a >> b;
}

void init(){
}

void solve(){
	cout << a * binaryExponentiation(b, MOD - 2) % MOD;
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

	return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// 