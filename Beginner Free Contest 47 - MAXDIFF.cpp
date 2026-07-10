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
const int    N          = 3e5 + 5;
const int    VAL        = 1e6 + 6;
const int    MOD        = 1e9 + 7;
const int    INF        = 0x3f3f3f3f3f3f3f3f;

int n, a[N], fL[N], fR[N], s;
priority_queue<int> R;
priority_queue<int, vector<int>, greater<int>> L;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n;
    forUp (i, 1, 3 * n, 1) cin >> a[i];
    s = 0;
    forUp (i, 1, 3 * n, 1) {
        s += a[i];
        L.push(a[i]);
        if (SZ(L) > n) {
            s -= L.top();
            L.pop();
        }
        fL[i] = s;
    }

    s = 0;
    forDown (i, 3 * n, 1, -1) {
        s += a[i];
        R.push(a[i]);
        if (SZ(R) > n) {
            s -= R.top();
            R.pop();
        }
        fR[i] = s;
    }

    int res = -INF;
    forUp (i, n, 2 * n, 1) res = max(res, fL[i] - fR[i + 1]);
    cout << res;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/fcb047_maxdiff
// https://oj.vnoi.info/problem/fct053_seq3n
// https://oj.vnoi.info/problem/fct017_seq3n
// https://oj.vnoi.info/problem/fc098_seq3n