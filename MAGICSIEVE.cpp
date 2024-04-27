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
const int LIM = 2e7 + 7;
vector<int> prime, lpf;

// (Sàng số nguyên tố tuyến tính) + (6k +- 1) --> O(N / 6)

void sieve(int n){
	prime.assign(1, 2);
	prime.push_back(3);
	lpf.assign(n + 1, 2);
	lpf[3] = 3;
	forUp(x, 5, n, 6){
		if(lpf[x] == 2) prime.push_back(lpf[x] = x);
		for(int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; i++)
			lpf[prime[i] * x] = prime[i];
		int j = x + 2; 
		if(lpf[j] == 2) prime.push_back(lpf[j] = j);
		for(int i = 0; i < prime.size() && prime[i] <= lpf[j] && prime[i] * j <= n; i++)
			lpf[prime[i] * j] = prime[i];
	}
}

void input(){
	if(fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
}

void init(){
	sieve(LIM);
	cout << prime.size();
	// for(auto it : prime) cout << it << endl;
}

void solve(){
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