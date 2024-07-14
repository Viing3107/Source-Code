/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 23:14:25 - 12/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define endl                    "\n"

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, a[N], dp[N], b[30], x;

void bruteForce() {
    forUp(i, 1, n, 1) {
        if (i == 1) dp[i] = 1;
        else {
            forUp(j, 1, i - 1, 1) (dp[i] += dp[j] * __builtin_popcountll(a[i] & a[j])) %= MOD;
        }
    }
    cout << dp[n];
}

void solve() {
    forUp(i, 1, n, 1) {
        if (i == 1) dp[i] = 1;
        else {
            forUp(j, 0, 30, 1) {
                if (a[i] >> j & 1) (dp[i] += b[j]) %= MOD;
            }
        }
        forUp(j, 0, 30, 1) {
            if (a[i] >> j & 1) (b[j] += dp[i]) %= MOD;
        }
    }
    cout << dp[n];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    forUp(i, 1, n, 1) cin >> a[i];
    solve();
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fct016_warp