/*
    Author: Do Quang Vinh
    VNU University of Engineering and Technology, Hanoi, Vietnam
    Created: 15:03:07 29/08/2026

*/

#include <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
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
const double    EPS         = 1e-6;
const int       N           = 1e2 + 5;
const int       MOD         = 1e9;
const int       INF         = 0x3f3f3f3f3f3f3f3f;

int n, m, a[N][N], dp[N][N];
/* 
dp[x][y]: số cách di chuyển từ cột 1 đến ô (x, y)
dp[x][y] += dp[i][j] với mọi i, j thỏa mãn i <= x, j <= y, i + j < x + y, gcd(a[i][j], a[x][y]) = 1
*/

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> m;
    forUp (i, 1, n, 1) forUp (j, 1, m, 1) cin >> a[i][j];

    if (1 < m) forUp (i, 1, n, 1) dp[i][1] = 1;
    forUp (i, 2, n, 1) {
        forUp (i1, 1, i - 1, 1) if (gcd(a[i1][1], a[i][1]) > 1) (dp[i][1] += dp[i1][1]) %= MOD;
    }
    forUp (x, 1, n, 1) {
        forUp (y, 2, m, 1) {
            forUp (i, 1, x, 1) {
                forUp (j, 1, y, 1) if (j < m && i + j < x + y && gcd(a[i][j], a[x][y]) > 1) (dp[x][y] += dp[i][j]) %= MOD;
            }
        }
    }
    // forUp (i, 1, n, 1) forUp (j, 1, m, 1) cout << dp[i][j] << " \n"[j == m];
    int res = 0;
    forUp (i, 1, n, 1) (res += dp[i][m]) %= MOD;
    cout << res;

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    />0   \>1
*/

// https://oj.vnoi.info/problem/nkpath