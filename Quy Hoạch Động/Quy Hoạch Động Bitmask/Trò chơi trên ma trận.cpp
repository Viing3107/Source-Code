/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 08:45:51 - 21/10/2024

*/

#include                            <bits/stdc++.h>
#define     endl                    "\n"
#define     task                    "test"
#define     int                     long long
#define     double                  long double
#define     MASK(i)                 (1ll << i)
#define     BIT(i, n)               (n >> i & 1)
#define     SZ(v)                   (int) v.size()
#define     all(v)                  v.begin(), v.end()
#define     LOG(x)                  (63 - __builtin_clzll(x))
#define     forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define     forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define     forEach(it, v)          for (typeof v.begin() it = v.begin(), _e = it.end(); it != _e; it++)

using namespace std;

const int       N           = 1e4 + 4;
const int       MOD         = 1e9 + 7;
const int       BLOCK_SIZE  = sqrt(N) + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, dp[N][MASK(8) + 8], a[10][N], ok[MASK(8) + 8];

/*
    gọi dp[j][mask] là tổng lớn nhất khi xét đến cột thứ j và đang có trạng thái là mask


*/

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    forUp(mask, 0, MASK(8) - 1, 1) {
        ok[mask] = 1;
        forUp(i, 0, 6, 1) if (BIT(i, mask) + BIT(i + 1, mask) == 2) {
            ok[mask] = 0;
            break;
        }
    }
    // forUp(mask, 0, MASK(8) - 1, 1) cout << mask << " " << ok[mask] << endl;
    cin >> n;
    forUp(i, 1, 8, 1) forUp(j, 1, n, 1) cin >> a[i][j];
    forUp(mask, 0, MASK(8) - 1, 1) if (ok[mask]) {
        forUp(i, 0, 7, 1) if (BIT(i, mask)) dp[1][mask] += a[i + 1][1];
    }
    forUp(j, 2, n, 1) forUp(mask, 0, MASK(8) - 1, 1) if (ok[mask]) {
        int sum = 0;
        forUp(i, 0, 7, 1) if (BIT(i, mask)) sum += a[i + 1][j];
        forUp(preMask, 0, MASK(8) - 1, 1) if (ok[preMask] && !(mask & preMask)) dp[j][mask] = max(dp[j][mask], dp[j - 1][preMask] + sum);
    }
    int res = -INF;
    res = *max_element(dp[n], dp[n] + MASK(8));
    if (!res) {
        res = -INF;
        forUp(i, 1, 8, 1) res = max(res, *max_element(a[i] + 1, a[i] + n + 1));
    }
    cout << res;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/qbgame