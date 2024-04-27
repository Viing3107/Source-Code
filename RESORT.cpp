# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forEach(it, v) for (typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)
# define forUp(variable, start, end, step) for (int variable = start; variable <= end; variable += step)
# define forDown(variable, start, end, step) for (int variable = start; variable >= end; variable -= step)

using namespace std;

const int LIM = 2e5 + 5;
const int N = 1e5 + 5;
int n, q, a[N], preSum[N], b[N], i, res;
map<int, int> mp;
vector<int> prime, lpf;

void sieve(int n){
	prime.assign(1, 2);
	lpf.assign(n + 1, 2);
	forUp(x, 3, n, 2){
		if (lpf[x] == 2) prime.push_back(lpf[x] = x);
		for(int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; i++) lpf[prime[i] * x] = prime[i];
	}
}

bool isPrime(int n){
	return n >= 2 && lpf[n] == n;
}

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n;
	forUp(i, 1, n, 1){
		cin >> a[i];
		mp[a[i]]++;
	}
}

void init(){
	if(mp.count(2)){
		b[1] = 2;
		mp[2]--;
	}
	if(mp.count(1)){
		b[2] = 1;
		mp[1]--;
	}
	else{
		b[2] = 2;
		mp[2]--;
	}
	i = 3;
	while(mp[2]){
		b[i] = 2;
		i++;
		mp[2]--;
	}
	while(mp[1]){
		b[i] = 1;
		i++;
		mp[1]--;
	}
	forUp(i, 1, n, 1) preSum[i] = preSum[i - 1] + b[i];
	sieve(LIM);
	res = 0;
}

void solve(){
	forUp(i, 1, n, 1) res += isPrime(preSum[i]);
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

// https://oj.vnoi.info/problem/bedao_g07_resort