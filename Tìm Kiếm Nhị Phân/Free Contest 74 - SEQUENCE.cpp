/*
    Author : Do Quang Vinh
    Vietnam National University - Ha Noi
    Created : 17:52:19 - 21/11/2025

*/

#include <bits/stdc++.h>
#define endl                   "\n"
#define task                   "test"
#define int                    long long
#define double                 long double
#define gcd(x, y)              __gcd(x, y)
#define MASK(i)                (1ll << (i))
#define BIT(i, n)              ((n) >> (i) & 1)
#define SZ(v)                  (int)(v).size()
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
const int    N          = 1e5 + 5;
const int    VAL        = 1e6 + 6;
const int    MOD        = 1e9 + 7;
const int    INF        = 0x3f3f3f3f3f3f3f3f;

int n, k, a[N], b[N], res, preSumA[N], preSumB[N], L, R;

bool f(int x) {
    forUp (i, 1, n, 1) {
        b[i] = a[i] - x;
        preSumB[i] = preSumB[i - 1] + b[i];
    }
    int tmp = 1e18;
    for (int i = 0, j = 1; j <= n; j++) {
        while (i <= j && preSumA[j] - preSumA[i] >= k) {
            tmp = min(tmp, preSumB[i]);
            i++;
        }
        if (preSumB[j] - tmp >= 0) return true;
        i--;
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> k;
    forUp (i, 1, n, 1) {
        cin >> a[i];
        preSumA[i] = preSumA[i - 1] + a[i];
    }
    int l = 0, r = 1e9;
    while (r - l >= 0) {
        int m = l + r >> 1;
        if (f(m)) {
            res = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    cout << res << endl;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/fc074_sequence