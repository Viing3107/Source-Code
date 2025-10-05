# include <bits/stdc++.h>
# define int long long
# define endl "\n"

using namespace std;

const int N = 1e5 + 5, base = 31, MOD = 1e9 + 7;
string a, b;
int n, m, hashA[N], hashB[N];

int binaryExponentiation(int a, int b){
	int res = 1;
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

int getHash(int l, int r, int arr[]){
	return ((arr[r] - arr[l - 1] * binaryExponentiation(base, r - l + 1)) % MOD + MOD) % MOD;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> a >> b;
	n = a.size();
	m = b.size();
	a = "!" + a;
	b = "!" + b;
	for (int i = 1; i <= n; i++) hashA[i] = (hashA[i - 1] * base + a[i] - 'a' + 1) % MOD;
	for (int i = 1; i <= m; i++) hashB[i] = (hashB[i - 1] * base + b[i] - 'a' + 1) % MOD;
	for (int i = n >= m ? n - m + 1 : 1, j = n >= m ? m : n; i <= n && j >= 1; i++, j--){
		if (getHash(i, n, hashA) == getHash(1, j, hashB)){
			for (int k = 1; k <= n; k++) cout << a[k];
			for (int l = j + 1; l <= m; l++) cout << b[l];
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) cout << a[i];
	for (int j = 1; j <= m; j++) cout << b[j];
	
	return 0;
}

// https://oj.vnoi.info/problem/c11str2
