/*
    Author : Do Quang Vinh
    Vietnam National University - Ha Noi
    Created : 16:50:57 - 17/11/2025

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define gcd(x, y)               __gcd(x, y)
#define MASK(i)                 (1ll << (i))
#define BIT(i, n)               ((n) >> (i) & 1)
#define SZ(v)                   (int) (v).size()
#define lcm(x, y)               x / gcd(x, y) * y
#define ALL(v)                  (v).begin(), (v).end()
#define LOG(x)                  (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof (v).begin() it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int       BASE        = 311;
const int       BLOCK_SIZE  = 320;
const int       N           = 1e5 + 5;
const int       VAL         = 1e6 + 6;
const int       MOD         = 1e9 + 7;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-4;

int n, k, a[N], l, r;
double b[N];

bool f(int x) {
    forUp (i, 1, n, 1) b[i] = a[i];
    forUp (i, 1, n, 1) {
        b[i] -= x * k;
        if (b[i] < 0 && abs(b[i]) > EPS) b[i + 1] += b[i];
    }
    return b[n] <= 0;
}

bool g(int x) {
    forUp (i, 1, n, 1) b[i] = a[i];
    forUp (i, 1, n, 1) {
        b[i] -= x * k;
        if (b[i] > 0 && abs(b[i]) > EPS) return false;
        b[i + 1] += b[i];
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> k;
    forUp (i, 1, n, 1) cin >> a[i];
    l = 0, r = 1e9;
    int res1 = INF;
    while (r - l >= 0) {
        int m = l + r >> 1;
        if (f(m)) {
            res1 = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << res1 << " ";
    
    l = 0, r = 1e9;
    int res2 = INF;
    while (r - l >= 0) {
        int m = l + r >> 1;
        if (g(m)) {
            res2 = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << res2;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/fcb021_waterfill