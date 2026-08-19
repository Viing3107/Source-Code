/*
    Author: Do Quang Vinh
    VNU University of Engineering and Technology, Hanoi, Vietnam
    Created: 00:36:52 20/08/2026

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
const int    INF        = 0x3f3f3f3f3f3f3f3f;

string a, b;
int A, MOD, res = 1;

int binpow(int a, int n) {
    int res = 1;
    for (; n; n >>= 1, (a *= a) %= MOD) if (n & 1) (res *= a) %= MOD;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> a >> b >> MOD;
    // for (auto &d : a) cout << d << " ";
    for (auto &d : a) A = (A * 10 + d - '0') % MOD;
    for (auto &d : b) res = (binpow(res, 10) * binpow(A, d - '0')) % MOD;
    cout << res;

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    />0   \>1
*/

// https://oj.vnoi.info/problem/fcb013_bigmod