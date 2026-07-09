/*
    Author : Do Quang Vinh
    Vietnam National University - Ha Noi
    Created : 17:52:19 - 21/11/2025

*/

#include <bits/stdc++.h>
#define endl                   "\n"
#define task                   "test"
#define gcd(x, y)              __gcd(x, y)
#define MASK(i)                (1ll << (i))
#define BIT(i, n)              ((n) >> (i) & 1)
#define SZ(v)                  (int)(v).size()
#define lcm(x, y)              x / gcd(x, y) * y
#define ALL(v)                 (v).begin(), (v).end()
#define LOG(x)                 (31 - __builtin_clz(x))
#define forUp(i, l, r, step)   for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step) for (int i = (l); i >= (r); i += step)

using namespace std;

const int    LEVEL      = 20;
const int    BASE       = 311;
const int    BLOCK_SIZE = 320;
const double EPS        = 1e-6;
const int    N          = 5e3 + 5;
const int    VAL        = 1e6 + 6;
const int    MOD        = 1e9 + 7;

int n, l, a[N];

// cách 1: dùng Sparse Table
// namespace SparseTable {
//     int cnt[N][N][LOG(N) + 1];

//     void build() {
//         forUp (i, 1, n, 1) forUp (j, i + 1, n, 1) cnt[i][j][0] = a[i] != a[j];
//         for (int k = 1; MASK(k) <= n; k++) {
//             for (int i = 1; i + MASK(k) - 1 <= n; i++) 
//                 for (int j = i + 1; j + MASK(k) - 1 <= n; j++) 
//                     cnt[i][j][k] = cnt[i][j][k - 1] + cnt[i + MASK(k - 1)][j + MASK(k - 1)][k - 1];
//         }
//     }

//     int get(int i, int j) {
//         int res = 0;
//         for (int k = LOG(l); k >= 0; k--) {
//             if (BIT(k, l)) {
//                 res += cnt[i][j][k];
//                 i += MASK(k);
//                 j += MASK(k);
//             }
//         }
//         return res;
//     }

//     void solve() {
//         build();
//         int res = 0;
//         forUp (i, 1, n - 1, 1) forUp (j, i + 1, n, 1) res = max(res, get(i, j));
//         cout << res;
//     }
// }

// cách 2: dùng Prefix
namespace DynamicProgramming {
    int dp[N][N];

    void build() {
        forUp (j, 1, n, 1) dp[1][j] = a[1] != a[j];
        forUp (i, 2, n - 1, 1) forUp (j, i + 1, n, 1) dp[i][j] = dp[i - 1][j - 1] + (a[i] != a[j]);
    }

    void solve() {
        build();
        int res = 0;
        forUp (i, l, n - 1, 1) forUp (j, i + 1, n, 1) res = max(res, dp[i][j] - dp[i - l][j - l]);
        cout << res;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> l;
    forUp (i, 1, n, 1) cin >> a[i];
    
    DynamicProgramming::solve();

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/fc104_diffsub