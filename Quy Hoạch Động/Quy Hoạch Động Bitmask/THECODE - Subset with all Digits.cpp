/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 13:05:57 - 22/10/2024

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

const int       N           = 1e3 + 3;
const int       MOD         = 1e9 + 7;
const int       BLOCK_SIZE  = sqrt(N) + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int t, n, d, a[N], dp[MASK(10) + 5];

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
        memset(a, 0, sizeof a);
        memset(dp, 0x3f, sizeof dp);
        cin >> n >> d;
        forUp(i, 1, n, 1) {
            string s;
            cin >> s;
            forUp(j, 0, d - 1, 1) a[i] |= MASK(s[j] - '0');
        }
        // forUp(i, 1, n, 1) cout << a[i] << " \n"[i == n];
        forUp(i, 1, n, 1) dp[a[i]] = 1;
        forUp(mask, 0, MASK(10) - 1, 1) forUp(i, 1, n, 1)
            dp[mask | a[i]] = min(dp[mask | a[i]], dp[mask] + 1);
        if (dp[MASK(10) - 1] == INF) cout << -1 << endl;
        else cout << dp[MASK(10) - 1] << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://www.spoj.com/problems/THECODE/