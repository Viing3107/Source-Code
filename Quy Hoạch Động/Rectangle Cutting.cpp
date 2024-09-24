#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e2 + 2;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n, m, dp[N][N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++) dp[i][1] = i - 1;
    for (int j = 1; j <= m; j++) dp[1][j] = j - 1;
    for (int i = 1; i <= min(n, m); i++) dp[i][i] = 0;
    for (int i = 2; i <= n; i++) for (int j = 2; j <= m; j++) if (i != j) {
        for (int k = 1; k * 2 <= i; k++) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
        for (int k = 1; k * 2 <= j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
    }
//    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cout << dp[i][j] << " \n"[j == m];
    cout << dp[n][m];
}

// https://cses.fi/problemset/task/1744
