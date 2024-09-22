#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 2;
const int K = 1e5 + 5;

int n, k, a[N], dp[K];

/*
    dp[i] = 1/0 : Taro thắng/thua với i viên đá
    nếu Taro thua với i - a[j] viên đá -> Taro thắng với i viên đá
    nếu Taro thắng với i - a[j] viên đá -> Taro thua với i viên đá
*/

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[a[i]] = 1;
    }
    for (int i = 1; i <= k; i++) if (!dp[i]) {
        for (int j = 1; j <= n; j++) if (i - a[j] >= 0) dp[i] = dp[i] | (dp[i - a[j]] ^ 1);
    }
//    for (int i = 1; i <= k; i++) cout << dp[i] << " ";
    if (dp[k]) cout << "First";
    else cout << "Second";
}

// https://oj.vnoi.info/problem/atcoder_dp_k
