# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forEach(it, v) for(typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)
# define forUp(variable, start, end, step) for(int variable = start; variable <= end; variable += step)
# define forDown(variable, start, end, step) for(int variable = start; variable >= end; variable += step)

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int n, k, a[N], factorial[N], res;

int binaryExponentiation(int a, int b){
	int res = 1;
	while(b){
		if (b & 1){
			res *= a;
			res %= MOD;
		}
		b >>= 1;
		a *= a;
		a %= MOD;
	}
	return res;
}

int C(int k, int n){
	if (k == 1 || k == n) return n / k;
	return factorial[n] * binaryExponentiation((factorial[k] * factorial[n - k]) % MOD, MOD - 2) % MOD;
}

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n >> k;
	forUp(i, 1, k, 1) cin >> a[i];
}

void init(){
	factorial[0] = 1;
	forUp(i, 1, N, 1) factorial[i] = (factorial[i - 1] * i) % MOD;
}

void solve(){
	res = 1;
	forUp(i, 1, k, 1){
		res *= C(a[i], n);
		res %= MOD;
		n -= a[i];
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
	
	return 0;
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/bedao_m04_fparty