# include <bits/stdc++.h>
# define int long long
# define task "test"
# pragma GCC optimize ("O2", "O3", "Ofast")
# pragma target ("avx", "avx2", "fma") 

using namespace std;

mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r){
    return l + (rng() * rng() % (r - l + 1) + (r - l + 1)) % (r - l + 1);
}

const int N = 2e6 + 4;
int n, l, r, m, res;

int f(int m){
	int res = 0;
	int lim = min(N, m);
	for (int i = 1; i <= lim; i++) res += i * (lim - i + 2);
	return res - 1;
}

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n;
}

void init(){
	l = 0;
	r = n;
}

void solve(){
	while (r - l >= 0){
		m = (l + r) / 2;
		if (f(m) <= n){
			res = m;
			l = m + 1;
		}
		else r = m - 1;
	}
}

void output(){
	cout << res;
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

// https://oj.vnoi.info/problem/fc067_dike