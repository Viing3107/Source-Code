// code by viing3107
#include <bits/stdc++.h>
#define int long long
#define task "test"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define forEach(it, v) for(typeof v.begin() it = v.begin(), _e = v.end(); it != _e; it++)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

int q, a, b, x, y, tmp;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> q;
    while (q--){
        cin >> a >> b;
        if (a == -b || !b) cout << 0 << " " << 0 << endl;
        else if (!a) cout << 0 << " " << 1 << endl;
        else{
            tmp = gcd(a, b);
            x = a / tmp;
            y = b / tmp;
            if ((abs(x) > abs(y) && x < 0 && y > 0) || (abs(x) < abs(y) && x > 0 && y < 0)) cout << -x << " " << -y << endl;
            else cout << x << " " << y << endl;
        }
    }

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << ".\n";

	return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/bedao_r18_a