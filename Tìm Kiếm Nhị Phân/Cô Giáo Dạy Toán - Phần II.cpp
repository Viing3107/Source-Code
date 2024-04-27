# include <bits/stdc++.h>
# define endl "\n"
# pragma GCC optimize("O2")
# define name "test"

using namespace std;

const int N = 20;
const double eps = 1e-6;
int n;
double a[N], l, r, m, res, x;

double f(double m){    // tính hàm số với ẩn m
    double res = 0;
    double x = 1;
    for(int i = 0; i <= n; i++){
    	res += x * a[i];
    	x *= m;
    }
    return res;
}

void input(){
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	cin >> n;
	for (int i = 0; i <= n; i++) cin >> a[i];
}

void init(){
}

void solve(){
	l = -1e6;
	r = 1e6;
	if(f(l) > f(r)){  // xét xem hàm số đồng biến hay nghịch biến
		for(int i = 0; i <= n; i++) a[i] *= -1;  // nếu nghịch biến --> quy về đồng biến
	}
	while (abs(r - l) >= eps){  // chặt nhị phân trên số thực
		m = 1.0 / 2.0 * (l + r);
		x = f(m);
		if (x > 0){
			r = m;
			res = m;
		}
		else l = m;
	}
	cout << int(m * 1000);
}

void output(){
	
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
	output();

	return(0);
}

// https://oj.vnoi.info/problem/cruell2