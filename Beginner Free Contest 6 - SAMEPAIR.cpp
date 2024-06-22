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
const int LIM = 1e6 + 6;
vector<int> prime, lpf;
int l, r, a[LIM], res;
map<int, int> mp;

void sieve(int n){
	prime.assign(1, 2);
	lpf.assign(n + 1, 2);
	forUp(x, 3, n, 2){
		if(lpf[x] == 2) prime.push_back(lpf[x] = x);
		for(int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; i++)
			lpf[prime[i] * x] = prime[i];
	}
}

int mul(int n){
	int res = 1;
	while(n != 1){
		int y = lpf[n];
		if(n % y == 0){
			while(n % y == 0) n /= y;
			res *= y;
		}
	}
	return res;
}

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> l >> r;
}

void init(){
	sieve(LIM);
	forUp(i, 2, LIM - 1, 1) a[i] = mul(i);
}

void solve(){
	forUp(i, l, r, 1) mp[a[i]]++;
	res = 0;
	for(auto it : mp) res += it.second * (it.second - 1) / 2;
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

// https://oj.vnoi.info/problem/fcb006_samepair
