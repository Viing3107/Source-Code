#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int MAX_ELEMENT = 1e9;
const int LOG = __lg(MAX_ELEMENT) + 5;
const int MOD = 1e9 + 7;

int n, a[N], dp[N], mask[LOG];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; (1ll << i) <= MAX_ELEMENT; i++) if (a[1] >> i & 1) (mask[i] += 1) %= MOD;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; (1ll << j) <= MAX_ELEMENT; j++) if (a[i] >> j & 1) (dp[i] += mask[j]) %= MOD;
        for (int j = 0; (1ll << j) <= MAX_ELEMENT; j++) if (a[i] >> j & 1) (mask[j] += dp[i]) %= MOD;
    }
    cout << dp[n];
}

// https://oj.vnoi.info/problem/fc112_warp