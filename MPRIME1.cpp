# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
# define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
# define forEach(it, v) for(typeof(v.begin()) it = v.begin(), _e = v.end(); it != _e; it++)
# pragma GCC optimize("O2", "O3", "Ofast")
# pragma target("avx", "avx2", "fma")

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int LIM = 11111;
const int N = 1345;
int n, pre[N + 1], l, r, m, res;
vector<int> prime, lpf;
map<int, int> mp;

void sieve(int n){
	prime.push_back(2);
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
	prime[0] = 2;
	prime.insert(prime.begin(), 0);
}

void input(){
	if(fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
}

void init(){
	sieve(LIM);
	forUp(i, 1, N, 1) pre[i] = pre[i - 1] + prime[i];
}

void solve(){
	while(true){
		cin >> n;
		if(!n) return;
		if(mp.count(n)) cout << mp[n] << endl;
		else{
			res = 0;
			forUp(i, 1, N, 1){
				if(prime[i] > n) break;
				l = i;
				r = N;
				while(r - l >= 0){
					m = (l + r) / 2;
					if(pre[m] - pre[i - 1] == n){
						res++;
						break;
					}
					else if(pre[m] - pre[i - 1] < n) l = m + 1;
					else r = m - 1;
				}
			}
			mp[n] = res;
			cout << res << endl;
		}
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

	return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/mprime1