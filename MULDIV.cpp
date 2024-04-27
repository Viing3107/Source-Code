# include <bits/stdc++.h>
# define int long long
# define task "test"

using namespace std;

const int MOD = 998244353, LIM = 1e7 + 7;
int q, n, tmp, res, x;
map<int, int> mp;
vector<int> prime, lpf;

int binaryExponentiation(int a, int b){
	int res = 1;
	while (b){
		if (b & 1){
			res *= a;
			res %= MOD;
		}
		b >>= 1;
		a *= a;
		a %= MOD;
	}
	return res;
}

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
}

// Sàng nguyên tố tuyến tính O(n)
void init(int n){
	prime.assign(1, 2);
	lpf.assign(n + 1, 2);
	for (int x = 3; x <= n; x += 2){
		if (lpf[x] == 2) prime.push_back(lpf[x] = x);
		for (int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; i++) lpf[prime[i] * x] = prime[i];
	}
}

int cnt(int n){
	int res = 1;
	while (n > 1){
		int y = lpf[n];
		int p = 0;
		while (n % y == 0){
			p++;
			n /= y;
		}
		res *= (p + 1);
	}
	return res;
}

void solve(){
	cin >> q;
	while (q--){
		cin >> n;
		if (mp.count(n)) cout << mp[n] << endl;
		else{
			tmp = cnt(n);
			res = binaryExponentiation(n, tmp / 2);
			x = sqrt(n);
			if (tmp % 2) mp[n] = res * x % MOD;
			else mp[n] = res % MOD;
			cout << mp[n] << endl;
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
	init(LIM);
	solve();
	output();

	return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/bedao_g02_muldiv