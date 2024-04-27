# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# define name "test"
# define gcd(a, b) __gcd(a, b)
# define lcm(a, b) a / gcd(a, b) * b
# define TR(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
# define pi M_PI

using namespace std;

int q, r1, r2;
double ans, res, t1, t2, t3, t4, alpha, be, theta;

void input(){
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
}

void init(){
}

void solve(){
	cin >> q;
	while (q--){
		cin >> r1 >> r2;
		alpha = atan(1.0 / (r1 + r2) * r1);
		be = 1.0 / 2.0 * pi - alpha;
		theta = pi - 2 * be;
		t1 = 1.0 / 2.0 * r1 * (r1 + r2);
		t2 = 1.0 / 2.0 * r1 * r1 * sin(theta);
		t3 = 1.0 / (2 * pi) * pi * r2 * r2 * alpha;
		t4 = 1.0 / (2 * pi) * pi * r1 * r1 * (1.0 / 2.0 * pi - theta);
		cout << fixed << setprecision(4) << t1 - t2 - t3 - t4 << endl;
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

// https://oj.vnoi.info/problem/bedao_g08_geometry