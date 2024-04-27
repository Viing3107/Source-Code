# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 1e6 + 61;
ll t, n; 
// check prime cuc ao ma
vector<ll> prime, lpf;

void sieve(int n){
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);
    for (int x = 3; x <= n; x += 2){
        if (lpf[x] == 2) prime.push_back(lpf[x] = x);
        for (int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; i++) lpf[prime[i] * x] = prime[i];
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	sieve(N);
	vector<ll> multi(prime.size() - 1);
	for (int i = 0; i < multi.size(); i++) multi[i] = 1ll * prime[i] * prime[i + 1];
	cin >> t;
	while (t--){
		cin >> n;
		ll res = upper_bound(multi.begin(), multi.end(), n) - multi.begin() - 1;
		cout << n - multi[res] << endl;
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/tht21_skc_brick
