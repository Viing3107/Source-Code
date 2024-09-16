#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 6;
const int MOD = 1e9;

int k, n, dp[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n >> k;
    dp[0] = 2;
    dp[1] = 2;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] * 2) % MOD;
        if (i >= k) (((dp[i] -= dp[i - k - 1]) %= MOD) += MOD) %= MOD;
    }
    cout << dp[n];
}

// https://oj.vnoi.info/problem/binary2
