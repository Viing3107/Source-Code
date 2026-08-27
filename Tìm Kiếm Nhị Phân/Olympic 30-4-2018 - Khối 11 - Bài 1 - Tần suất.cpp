/*
    Author: Do Quang Vinh
    VNU University of Engineering and Technology, Hanoi, Vietnam
    Created: 15:02:30 27/08/2026

*/

#include <bits/stdc++.h>
#define endl                    "\n"
#define task                    "rate"
#define int                     long long
#define double                  long double
#define gcd(x, y)               __gcd(x, y)
#define MASK(i)                 (1ll << (i))
#define SZ(v)                   (int)(v).size()
#define BIT(i, n)               ((n) >> (i) & 1)
#define lcm(x, y)               x / gcd(x, y) * y
#define ALL(v)                  (v).begin(), (v).end()
#define LOG(x)                  (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)

using namespace std;

const int       LEVEL       = 20;
const int       BASE        = 311;
const int       BLOCK_SIZE  = 320;
const double    EPS         = 1e-8;
const int       N           = 3e5 + 5;
const int       MOD         = 1e9 + 7;
const int       INF         = 0x3f3f3f3f3f3f3f3f;

int n, k, a[N];
double b[N], preSum[N], minPre[N];

// liệu có tồn tại avg(a[i], ..., a[j]) >= m hay không (đk: j - i + 1 >= k)
bool f(double x) {
    forUp (i, 1, n, 1) b[i] = a[i] - x;

    forUp (i, 1, n, 1) {
        preSum[i] = preSum[i - 1] + b[i];
        minPre[i] = min(minPre[i - 1], preSum[i]);
        if (i >= k && preSum[i] - minPre[i - k] >= 0) return true;
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
    forUp (i, 1, n, 1) cin >> a[i];

    double l = 0, r = 1e6, res;
    while (r - l >= EPS) {
        double m = (l + r) / 2;
        if (f(m)) {
            res = m;
            l = m;
        }
        else r = m;
    }
    cout << fixed << setprecision(6) << res;

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    />0   \>1
*/

// https://oj.vnoi.info/problem/olp304_18_rate