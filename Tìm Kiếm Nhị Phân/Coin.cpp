#include <bits/stdc++.h>
#define int long long
#define name "test"
#define pi M_PI
#define eps 1e-9

using namespace std;

const int N = 1e4 + 4;
int n;
double a[N], l, r, m, x, res;

double cos(double a, double b, double c){
	return acos(1.0 / (2 * b * c) * (b * b + c * c - a * a));
}

void input(){
	# ifndef ONLINE_JUDGE
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	# endif
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
}

void init(){
	l = 0;
	r = 1e9;
}

void solve(){
	while (abs(r - l) >= eps){
		double m = 1.0 / 2.0 * (l + r);
        x = cos(a[n] + a[1], a[n] + m, a[1] + m);
        for (int i = 1; i < n; i++) x += cos(a[i] + a[i + 1], a[i] + m, a[i + 1] + m);  // tính tổng các góc
        if(x < 2 * pi){  // so sánh tổng vừa tìm được với 2 * pi (radian) <==> 360 (degree)
        	r = m;
        	res = m;
        }
        else l = m;
	}
}

void output(){
	cout << fixed << setprecision(3) << res << endl;
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

// https://oj.vnoi.info/problem/lem1
// C:\Users\Administrator\Downloads\COINS.doc