/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 11:15:27 - 13/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, dp[N][3];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    forUp(i, 0, 2, 1) dp[1][i] = 1;
    forUp(length, 2, n, 1) {
        dp[length][0] = (dp[length - 1][0] + dp[length - 1][1] + dp[length - 1][2]) % MOD;
        dp[length][1] = (dp[length - 1][0] + dp[length - 1][2]) % MOD;
        dp[length][2] = (dp[length - 1][0] + dp[length - 1][1] + dp[length - 1][2]) % MOD;
    }
    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb030_strin