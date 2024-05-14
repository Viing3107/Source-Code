# include <bits/stdc++.h>
# define endl "\n"
# define ll long long

using namespace std;

const ll base = 31, MOD = 1e9 + 7;
string a, b;
ll n, m, f[1000006];

ll be(ll a, ll b){
	ll res = 1;
	while (b){
		if (b % 2){
			res *= a;
			res %= MOD;
		}
		b /= 2;
		a *= a;
		a %= MOD;
	}
	return res;
}

ll getHash(int l, int r){
	return ((f[r] - f[l - 1] * be(base, r - l + 1)) % MOD + MOD) % MOD;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> a >> b;
	n = a.size();
	m = b.size();
	a = "!" + a;
	b = "!" + b;
	ll hashB = 0;
	for (int i = 1; i <= n; i++) f[i] = (f[i - 1] * base + a[i] - 'a' + 1) % MOD;
	for (int i = 1; i <= m; i++) hashB = (hashB * base + b[i] - 'a' + 1) % MOD;
	for (int i = 1; i + m - 1 <= n; i++){
		if (hashB == getHash(i, i + m - 1)) cout << i << " ";
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/substr
