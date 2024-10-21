/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 11:07:30 - 16/10/2024

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

const int       N           = 33;
const int       MOD         = 1e9 + 7;
const int       LOG         = __lg(N) + 5;
const int       BLOCK_SIZE  = sqrt(N) + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

/*
    quy ước: số cột <= số hàng <= 5
    gọi dp[i][mask] là số cách khi xét đến hàng thứ i và trạng thái hiện tại là mask
    dp[i][mask] += dp[i - 1][mask2] với mọi mask2 thỏa mãn

    dp[n][mask] với mọi mask

*/

int t, n, m, dp[N][MASK(7) + 5];

int check(int mask, int preMask) {
    forUp(i, 0, m - 2, 1) {
        int val = BIT(i, mask) + BIT(i + 1, mask) + BIT(i, preMask) + BIT(i + 1, preMask);
        if (!val || val == 4) return false;
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

    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (m > n) swap(n, m);
        memset(dp, 0, sizeof dp);
        forUp(mask, 0, MASK(m) - 1, 1) dp[1][mask] = 1;
        forUp(i, 2, n, 1) forUp(mask, 0, MASK(m) - 1, 1) {
            forUp(preMask, 0, MASK(m) - 1, 1) {
                if (check(mask, preMask)) dp[i][mask] += dp[i - 1][preMask];
            }
        }
        int res = 0;
        forUp(mask, 0, MASK(m) - 1, 1) res += dp[n][mask];
        cout << res << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/cowgirl