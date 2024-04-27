# include <bits/stdc++.h>
# define int long long
# define task "test"
# define gcd(a, b) __gcd(a, b)
# define lcm(a, b) a / gcd(a, b) * b
# define forEach(it, v) for(typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)
# define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
# define forDown(i, l, r, step) for(int i = l; i >= r; i += step)

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int n;

int binaryExponentiation(int a, int b){
	int res = 1;
	while(b){
		if(b & 1) res = (res * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res;
}

void input(){
	if(fopen("test.inp", "r")){
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	cin >> n;
}

void init(){
	
}

void solve(){
}

void output(){
	cout << binaryExponentiation(3, n - 1) % MOD << endl;
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

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/fc074_count