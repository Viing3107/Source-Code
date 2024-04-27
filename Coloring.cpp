// code by viing3107
#pragma GCC optimize("O2", "O3", "Ofast")
#pragma target("avx", "avx2", "fma")
#include <bits/stdc++.h>
#define int long long
#define double long double
#define task "test"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define forEach(it, v) for(typeof v.begin() it = v.begin(), _e = v.end(); it != _e; it++)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

const int N   = 2e5 + 5;
const int LIM = 9e5 + 5;
const int MOD = 3;

int n, xi, yi, type, x, y, z, t;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> z >> t >> n;
    forUp(i, 1, n, 1){
        cin >> xi >> yi >> type;
        if (x >= z || y >= t) break;
        if (type == 1) x = max(x, xi);
        else if (type == 2) z = min(z, xi);
        else if (type == 3) y = max(y, yi);
        else t = min(t, yi);
    }
    if (x >= z || y >= t) cout << 0;
    else cout << (z - x) * (t - y);

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb019_coloring
