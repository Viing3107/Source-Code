/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:50:35 - 09/10/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << i)
#define BIT(i, n)               (n >> i & 1)
#define SZ(v)                   (int) v.size()
#define all(v)                  v.begin(), v.end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof v.begin() it = v.begin(), _e = it.end(); it != _e; it++)

using namespace std;

const int       N           = 1e4 + 4;
const int       MOD         = 1e9 + 7;
const int       LOG         = __lg(N) + 5;
const int       BLOCK_SIZE  = sqrt(N) + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, a[4][N], dp[N][MASK(4) + 4];
bool ok[20];

/*
    gọi dp[i][mask] là tổng lớn nhất khi xét đến cột thứ i và trạng thái hiện tại là mask

*/

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    memset(ok, true, sizeof ok);
    for (int mask = 0; mask < MASK(4); mask++) {
        forUp(i, 0, 2, 1) if (BIT(i, mask) && BIT(i + 1, mask)) {
            ok[mask] = false;
            break;
        }
    }

    cin >> n;
    forUp(i, 0, 3, 1) forUp(j, 1, n, 1) cin >> a[i][j]; 
    // for (int mask = 0; mask < MASK(4); mask++) cout << mask << " " << ok[mask] << endl;
    memset(dp, -0x3f, sizeof dp);
    forUp(mask, 0, MASK(4) - 1, 1) dp[0][mask] = 0;
    forUp(j, 1, n, 1) for (int mask = 0; mask < MASK(4); mask++) if (ok[mask]) {
        int sum = 0;
        forUp(i, 0, 3, 1) if (BIT(i, mask)) sum += a[i][j];
        for (int preMask = 0; preMask < MASK(4); preMask++) if (ok[preMask] && !(mask & preMask)) 
            dp[j][mask] = max(dp[j][mask], dp[j - 1][preMask] + sum);
    }
    if (!*max_element(dp[n], dp[n] + MASK(4))) {
        int res = -INF;
        forUp(i, 0, 3, 1) res = max(res, *max_element(a[i] + 1, a[i] + n + 1));
        cout << res;
    }
    else cout << *max_element(dp[n], dp[n] + MASK(4));
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/qbselect