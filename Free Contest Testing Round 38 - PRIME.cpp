# include <bits/stdc++.h>
# define int long long
# define endl "\n"

using namespace std;

const int N = 1e6 + 6, MOD = 1e9 + 7;
int t, a, b, f[N], cnt[N], sum[N], result;
vector<int> prime, lpf;

void sieve(int n){
	prime.assign(1, 2);
	lpf.assign(n + 1, 2);
	for (int x = 3; x <= n; x += 2){
		if (lpf[x] == 2) prime.push_back(lpf[x] = x);
		for (int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; i++) lpf[prime[i] * x] = prime[i];
	}
}

void input(){
    if (fopen("test.inp", "r")){
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }

	cin >> t;
}

void init(){
	sieve(N);
	prime.insert(prime.begin(), 0);
	for (int i = 1; i < prime.size(); i++){
		f[i] = (f[i - 1] + i * prime[i]) % MOD;
		sum[i] = (sum[i - 1] + prime[i]) % MOD;
		cnt[i] = cnt[i - 1] + 1;
	}
}

void solve(){
	while (t--){
		cin >> a >> b;
        if (a > b) swap(a, b);
		a = lower_bound(prime.begin(), prime.end(), a) - prime.begin();
		b = upper_bound(prime.begin(), prime.end(), b) - prime.begin() - 1;
        result = f[b] - f[a - 1] - cnt[a - 1] * (sum[b] - sum[a - 1]);
		cout << (result % MOD + MOD) % MOD << endl;
	}
}

void output(){
	
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

// https://oj.vnoi.info/problem/fct038_prime