# include <bits/stdc++.h>
# define ll long long
# define endl "\n"

using namespace std;

const ll N = 256, base = 31, MOD = 1e9 + 7;
string s1, t1, s, t;
ll n, m, hashT[N], hashS[N], p[N];

ll getHash(int l, int r, ll arr[]){
	return ((arr[r] - arr[l - 1] * p[r - l + 1]) % MOD + MOD) % MOD;
}

int main(){
	
	cin >> s >> t;
	n = s.size();
	m = t.size();
	s = "!" + s;
	t = "!" + t;
	for (int i = 1; i <= n; i++) hashS[i] = (hashS[i - 1] * base + s[i] - 'a' + 1) % MOD;
	for (int i = 1; i <= m; i++) hashT[i] = (hashT[i - 1] * base + t[i] - 'a' + 1) % MOD;
	p[0] = 1;
	for (int i = 1; i <= max(n, m); i++) p[i] = (p[i - 1] * base) % MOD;
	for (int i = n; i >= 1; i--){
		if (getHash(n - i + 1, n, hashS) == getHash(1, i, hashT)){
			cout << n - i + m << endl;
			return 0;
		}
	}
	cout << n + m << endl;
	
    return 0;
}

// https://oj.vnoi.info/problem/nkletter
