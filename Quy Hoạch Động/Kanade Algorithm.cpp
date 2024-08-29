#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3e5 + 5;

int n, k, a[N], dp[N][3], val[N][3], preSum[N], result = LLONG_MIN;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        preSum[i] = preSum[i - 1] + a[i];
        dp[i][0] = preSum[i] - val[i - 1][0];
        dp[i][1] = preSum[i] * k + val[i - 1][1];
        dp[i][2] = preSum[i] + val[i - 1][2];
        val[i][0] = min(val[i - 1][0], preSum[i]);
        val[i][1] = max(val[i - 1][1], max(0ll, dp[i][0]) - preSum[i] * k);
        val[i][2] = max(val[i - 1][2], dp[i][1] - preSum[i]);
        result = max({result, dp[i][0], dp[i][1], dp[i][2]});
        // cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << "\n";
    }
    cout << result;
}

// https://oj.vnoi.info/problem/fc108_dpc7
// https://oj.vnoi.info/problem/dtqna_kadanepp