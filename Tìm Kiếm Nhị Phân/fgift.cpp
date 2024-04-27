# include <bits/stdc++.h>
# define int long long
# define name "fgift"

using namespace std;

const int N = 3e5 + 5;
int n, M, a[N], l, r, m, res;

bool f(int m){
	int res = 0;
	for (int i = 1; i <= n; i++) res += ceil((double) a[i] / m);
	if (res > M) return true;
	return false;
}

void input(){
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	cin >> M >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
}

void init(){
	l = 0;
	r = 3e14;
	res = 3e14;
}

void solve(){
	while (r - l >= 0){
		m = (l + r) / 2;
		if (f(m)) l = m + 1;
		else{
			res = m;
			r = m - 1;
		}
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

// https://lqdoj.edu.vn/problem/fgift
