#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, a[N], dp[N], res;

/*
    gọi dp[i] là giá trị cuối cùng của dãy con độ dài i
*/

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, 0x3f, sizeof dp);
    dp[1] = a[1];
    res = 1;
    for (int i = 2; i <= n; i++) {
        int idx = lower_bound(dp + 1, dp + res + 1, a[i]) - dp - 1;
        dp[idx + 1] = min(dp[idx + 1], a[i]);
        res = max(res, idx + 1);
    }
    cout << res;
}

// https://cses.fi/problemset/task/1145
