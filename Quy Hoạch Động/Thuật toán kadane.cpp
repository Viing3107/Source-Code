#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, a[N], dp[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen("test.inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + a[i];
        dp[i] = max(dp[i], a[i]);
    }
    cout << *max_element(dp + 1, dp + n + 1);
}
