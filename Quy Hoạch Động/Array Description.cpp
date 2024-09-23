#include <iostream>
#define int long long

using namespace std;

const int N = 1e5 + 5;
const int M = 1e2 + 2;
const int MOD = 1e9 + 7;

int n, m, a[N], dp[N][M];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (a[1]) dp[1][a[1]] = 1;
    else for (int i = 1; i <= m; i++) dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i]) (dp[i][a[i]] += dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1]) %= MOD;
        else {
            for (int j = 1; j <= m; j++) {
                (dp[i][j] += dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) %= MOD;
            }
        }
    }

    if (a[n]) cout << dp[n][a[n]];
    else {
        int res = 0;
        for (int i = 1; i <= m; i++) (res += dp[n][i]) %= MOD;
        cout << res;
    }
}

// https://cses.fi/problemset/task/1746
