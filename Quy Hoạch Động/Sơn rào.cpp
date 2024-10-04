/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:22:24 - 04/10/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define SZ(v)                   (int) v.size()
#define all(v)                  v.begin(), v.end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof v.begin() it = v.begin(), _e = it.end(); it != _e; it++)

using namespace std;

const int N             = 2e5 + 5;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int BLOCK_SIZE    = sqrt(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, k, dp[N][2], preSum[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> k;
    dp[1][0] = dp[1][1] = preSum[1] = 1;
    forUp(i, 2, k, 1) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = 1;
        preSum[i] = (preSum[i - 1] + dp[i][1]) % MOD;
    }
    forUp(i, k + 1, n, 1) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (preSum[i - k] + 1) % MOD;
        preSum[i] = (preSum[i - 1] + dp[i][1]) % MOD;
    }
    // forUp(i, 1, n, 1) forUp(j, 0, 1, 1) cout << dp[i][j] << " \n"[j];
    cout << (dp[n][0] + dp[n][1]) % MOD;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://marisaoj.com/problem/574