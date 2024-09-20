#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, t[N], r[N], dp[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 2; i <= n; i++) cin >> r[i];
    dp[1] = t[1];
    for (int i = 2; i <= n; i++) dp[i] = min(dp[i - 1] + t[i], dp[i - 2] + r[i]);
    cout << dp[n];
}

// https://marisaoj.com/problem/572
