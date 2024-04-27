# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# pragma GCC optimize("O2")

using namespace std;

const int N = 1e3 + 3;
int q, n, a[N], max_fre, i, j;

void input(){
	# ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	# endif
	cin >> q;
}

void init(){
	
}

void solve(){
	while (q--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		max_fre = 0;
		i = 1;
		while (i < n){
			j = i;
			while (j < n && abs(a[j] - a[j + 1]) == 1) j++;
			max_fre = max(max_fre, j - i + 1);
			i = j + 1;
		}
		if (max_fre > n / 2) cout << "Yes\n";
		else cout << "No\n";
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
	init();
	solve();
	output();

	return 0;
}

// https://oj.vnoi.info/problem/fcb006_harmony