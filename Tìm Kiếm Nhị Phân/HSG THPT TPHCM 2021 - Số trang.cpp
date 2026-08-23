/*
    Author: Do Quang Vinh
    VNU University of Engineering and Technology, Hanoi, Vietnam
    Created: 15:29:30 23/08/2026

*/

#include <bits/stdc++.h>
#define endl                   "\n"
#define task                   "test"
#define int                    long long
#define double                 long double
#define gcd(x, y)              __gcd(x, y)
#define MASK(i)                (1ll << (i))
#define SZ(v)                  (int)(v).size()
#define BIT(i, n)              ((n) >> (i) & 1)
#define lcm(x, y)              x / gcd(x, y) * y
#define ALL(v)                 (v).begin(), (v).end()
#define LOG(x)                 (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)   for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step) for (int i = (l); i >= (r); i += step)

using namespace std;

const int    LEVEL      = 20;
const int    BASE       = 311;
const int    BLOCK_SIZE = 320;
const double EPS        = 1e-6;
const int    N          = 3e5 + 5;
const int    VAL        = 1e6 + 6;
const int    MOD        = 1e9 + 7;
const int    INF        = 0x3f3f3f3f3f3f3f3f;

int n, p;

// x <= 1e4
int f(int x) {
    if (x < 10) return x;
    else if (x < 100) return 9 + 2 * (x - 10 + 1);
    else if (x < 1000) return 189 + 3 * (x - 100 + 1);
    else if (x < 10000) return 2889 + 4 * (x - 1000 + 1);
    else return 38889 + 5 * (x - 10000 + 1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n;
    n += 3;
    int l = 1, r = 1e4;
    while (r - l >= 0) {
        int m = l + r >> 1;
        if (f(m) < n) l = m + 1;
        else {
            p = m;
            r = m - 1;
        }
    }
    cout << p;

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    />0   \>1
*/

// https://oj.vnoi.info/problem/hcm_thpt_21_a