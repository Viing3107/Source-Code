# include <bits/stdc++.h>
# define int long long
# define task "test"
# define lcm(a, b) a / __gcd(a, b) * b
# define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
# define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
# define forEach(it, v) for(typeof(v.begin()) it = v.begin(), _e = v.end(); it != _e; it++)
# pragma GCC optimize("O2", "O3", "Ofast")
# pragma target("avx", "avx2", "fma")

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int LIM = 182580;
int n, k;
vector<int> prime, lpf, combinePrime;
string s;

void sieve(int n){
	prime.assign(1, 2);
	lpf.assign(n + 1, 2);
	forUp(x, 3, n, 2){
		if(lpf[x] == 2) prime.push_back(lpf[x] = x);
		for(int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; i++)
			lpf[prime[i] * x] = prime[i];
	}
}

int binaryMultiplication(int a, int b, int MOD){
	int res = 0;
	while(b){
		if(b & 1) res = (res + a) % MOD;
		b >>= 1;
		a = (a + a) % MOD;
	}
	return res;
}

int binaryExponentiation(int a, int b, int MOD){
	int res = 1;
	while(b){
		if(b & 1) res = binaryMultiplication(res, a, MOD);
		b >>= 1;
		a = binaryMultiplication(a, a, MOD);
	}
	return res;
}

bool RabinMiller(int n, int iteration){
	if(n < 3) return n == 2;
	if(!n % 2) return false;
	int s = n - 1, p = 0;
	while(!s % 2) s /= 2, p++;
	while(iteration--){
		int x = binaryExponentiation(rand() % (n - 1) + 1, s, n);
		forUp(i, 1, p, 1){
			int xx = x;
			x = x * x % n;
			if(x && xx != 1 && xx != n - 1) return false;
		}
		if(x != 1) return false;
	}
	return true;
}

void input(){
	if(fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> k;
}

void init(){
	sieve(LIM);
	n = prime.size();
	forUp(i, 0, n - 3, 2){
		if(combinePrime.size() > k) break;
		s = to_string(prime[i]) + to_string(prime[i + 1]);
		if(RabinMiller(stoll(s), 10)) combinePrime.push_back(stoll(s));
	}
}

void solve(){
}

void output(){
	cout << combinePrime[k - 1] << endl;
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

// https://oj.vnoi.info/problem/mprime
