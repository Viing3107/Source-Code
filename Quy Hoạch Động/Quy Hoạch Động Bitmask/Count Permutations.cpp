/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 14:02:13 - 22/10/2024

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
#define LOG(x)                  (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof v.begin() it = v.begin(), _e = it.end(); it != _e; it++)

using namespace std;

const int       N           = 20;
const int       MOD         = 1e9 + 7;
const int       BLOCK_SIZE  = sqrt(N) + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

/*
    dp[mask][i] là số hoán vị khi có trạng thái là mask và số cuối cùng là i

*/

int t, n, k, dp[MASK(N)][N];

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
        cin >> n >> k;
        memset(dp, 0, sizeof dp);
        forUp(i, 0, n - 1, 1) dp[MASK(i)][i] = 1;
        forUp(mask, 0, MASK(n) - 1, 1) forUp(i, 0, n - 1, 1) if (BIT(i, mask)) {
            forUp(j, 0, n - 1, 1) if (BIT(j, mask ^ MASK(i)) && abs(i - j) <= k) 
                dp[mask][i] += dp[mask ^ MASK(i)][j];
        }
        int res = 0;
        forUp(i, 0, n - 1, 1) res += dp[MASK(n) - 1][i];
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

// https://codeforces.com/gym/100589/problem/G