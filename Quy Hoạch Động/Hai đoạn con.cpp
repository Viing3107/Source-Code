/*
    Author: Do Quang Vinh
    VNU University of Engineering and Technology, Hanoi, Vietnam
    Created: 22:44:19 16/08/2026

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

int n, a[N], preSum[N], minPre[N], minSuf[N], maxRange[N], optRange[N];

/* 
minPre[i] là tổng get(1, j) nhỏ nhất với j <= i
minSuf[i] là tổng get(j, n) nhỏ nhất với j >= i
maxRange[i] là tổng lớn nhất của đoạn [i..v] với i < v <= n
optRange[i] là tổng lớn nhất của đoạn [u..v] với i <= u < v <= n
*/

int get(int l, int r) {
    return preSum[r] - preSum[l - 1];
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
    forUp (i, 1, n, 1) cin >> a[i];

    forUp (i, 1, n, 1) {
        preSum[i] = preSum[i - 1] + a[i];
        minPre[i] = min(minPre[i - 1], preSum[i]);
    }
    forDown(i, n, 1, -1) minSuf[i] = min(minSuf[i + 1], get(i, n));
    forUp (i, 1, n, 1) maxRange[i] = get(i, n) - minSuf[i + 1];
    optRange[n + 1] = -INF;
    forDown(i, n, 1, -1) optRange[i] = max(optRange[i + 1], maxRange[i]);
    // forUp (i, 1, n, 1) cout << preSum[i] << " \n"[i == n];
    // forUp (i, 1, n, 1) cout << minPre[i] << " \n"[i == n];
    // forUp (i, 1, n, 1) cout << minSuf[i] << " \n"[i == n];
    // forUp (i, 1, n, 1) cout << maxRange[i] << " \n"[i == n];
    // forUp (i, 1, n, 1) cout << optRange[i] << " \n"[i == n];

    int res = -INF;
    forUp (i, 1, n, 1) res = max({res, get(1, i) - minPre[i - 1] + optRange[i + 1]});
    cout << res;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/prefixsum_diff_e