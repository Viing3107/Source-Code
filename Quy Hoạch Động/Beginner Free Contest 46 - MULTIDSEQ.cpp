/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 23:53:35 - 09/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for(int i = (l); i >= (r); i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define endl                    "\n"

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, k, dp[55][N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> k;
    
    forUp (i, 1, n, 1) dp[1][i] = 1;
    forUp (length, 2, k, 1) {
        for (int i = 1; i * i <= n; i++) {
            for (int j = i * i; j <= n; j += i) {
                (dp[length][j] += dp[length - 1][i]) %= MOD;
                if (i != j / i) (dp[length][j] += dp[length - 1][j / i]) %= MOD;
            }
        }
    }
    int result = 0;
    forUp (i, 1, n, 1) (result += dp[k][i]) %= MOD;

    cout << result;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb046_multidseq