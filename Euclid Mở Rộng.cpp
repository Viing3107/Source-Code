#include <bits/stdc++.h>
#define int long long
#define name "test"

using namespace std;

// Cho hai số a, b. Tìm x, y thỏa a * x + b * y = gcd(a, b)

int x[20], y[20], cnt, a, b;

void extendedEuclid(int a, int b){
	if (b == 0){
		x[0] = 1;
		y[0] = 0;
		return;
	}
	extendedEuclid(b, a % b);
	cnt++;
	x[cnt] = y[cnt - 1];
	y[cnt] = x[cnt - 1] - a / b * y[cnt - 1];
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);

	cin >> a >> b;

	extendedEuclid(a, b);

	cout << x[cnt] << " " << y[cnt] << endl;

	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

	return 0;
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/bvd_diophantine