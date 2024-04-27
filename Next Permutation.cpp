# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# pragma GCC optimize("O2")

using namespace std;

const int N = 22;
int b, n, MOD, h[N], res, sum, i;
bitset<N> a, isFinal;

void next_perm(){
	i = n;
	while (i >= 1 && a[i] == 1){
		a[i] = 0;
		i--;
	}
	if (i == 0) isFinal = 1;
	else a[i] = 1;
}

void input(){
	# ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	# endif
	cin >> n >> b;
	for (int i = 1; i <= n; i++) cin >> h[i];
}

void init(){
	isFinal = 0;
	res = 1e9;
}

void solve(){
	while (isFinal == 0){
		sum = 0;
		for (int i = 1; i <= n; i++) sum += a[i] * h[i];
		if (sum < b){
			next_perm();
			continue;
		}
		res = min(res, abs(sum - b));
		if (!res) return;
		next_perm();
	}
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

// https://oj.vnoi.info/problem/fc016_shelf2