#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 4e2 + 2;

int n, a[N], dp[N][N], preSum[N];

int get(int l, int r) {
    return preSum[r] - preSum[l - 1];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        preSum[i] = preSum[i - 1] + a[i];
    }
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++) dp[i][i] = 0;
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + get(i, j));
            }
        }
    }
    cout << dp[1][n];
}

// https://oj.vnoi.info/problem/atcoder_dp_n