# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# define name "test"

using namespace std;

struct point{
	int x, y, r;
};

const int N = 1e5 + 5;
int n, a, b, l, r, m, res;
point p[N];

bool f(int m){
	for (int i = 1; i <= n; i++){
		int tmp = pow(a - p[i].x, 2) + pow(b - p[i].y, 2);
		double tmp2 = sqrt(tmp);
		if (tmp <= pow(m + p[i].r + 1, 2) && tmp2 <= m + p[i].r + 1) return false;
	}
	return true;
}

void input(){
	# ifndef ONLINE_JUDGE
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	# endif
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y >> p[i].r;
}

void init(){
	l = 0;
	r = 1e18;
}

void solve(){
	while (r - l >= 0){
		m = (l + r) / 2;
		if (f(m)){
			res = m;
			l = m + 1;
		}
		else r = m - 1;
	}
}

void output(){
	cout << res + 1;
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

// https://oj.vnoi.info/problem/olp_kc19_cow