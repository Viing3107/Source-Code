// code by viing3107
#pragma GCC optimize("O2", "O3", "Ofast")
#pragma target("avx", "avx2", "fma")
#include <bits/stdc++.h>
#define int long long
#define double long double
#define task "test"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

const int N = 2e5 + 5;
const int LIM = 1e6 + 6;

int a, b, c, xp, yp, xo, yo, xt, yt;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> xp >> yp >> xo >> yo >> xt >> yt;
    a = yt - yo;
    b = xo - xt;
    c = yo * xt - xo * yt;
    if (a * xp + b * yp + c == 0){
        if (xt > xo){
            if (yt > yo) cout << (xp >= xo && yp >= yo ? "YES\n" : "NO\n");
            else if (yt == yo) cout << (xp >= xo && yp == yo ? "YES\n" : "NO\n");
            else cout << (xp >= xo && yp <= yo ? "YES\n" : "NO\n");
        }
        else if (xt == xo){
            if (yt > yo) cout << (xp == xo && yp >= yo ? "YES\n" : "NO\n");
            else if (yt == yo) cout << (xp == xo && yp == yo ? "YES\n" : "NO\n");
            else cout << (xp == xo && yp <= yo ? "YES\n" : "NO\n");
        }
        else{
            if (yt > yo) cout << (xp <= xo && yp >= yo ? "YES\n" : "NO\n");
            else if (yt == yo) cout << (xp <= xo && yp == yo ? "YES\n" : "NO\n");
            else cout << (xp <= xo && yp <= yo ? "YES\n" : "NO\n");
        }
    }
    else cout << "NO\n";

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/geo_p
