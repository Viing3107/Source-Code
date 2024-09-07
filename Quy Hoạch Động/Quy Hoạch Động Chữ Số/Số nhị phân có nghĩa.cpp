#include <bits/stdc++.h>

using namespace std;

const int N = 33;

int n, k, dp[N][2][2][N];

int f(int i, int lower, int positive, int k, string &s) {
    if (k < 0) return 0;

    if (dp[i][lower][positive][k] != -1) return dp[i][lower][positive][k];

    if (i == s.size()) return !k;

    int ans = 0;
    for (int digit = 0; digit <= 1; digit++) {
        if (!lower && digit > s[i] - '0') continue;
        int lower2 = lower || digit < s[i] - '0';

        int positive2 = positive || digit > 0;

        int k2 = k;
        if (positive2 && !digit) k2--;

        ans += f(i + 1, lower2, positive2, k2, s);
    }

    return dp[i][lower][positive][k] = ans;
}

int calc(string s) {
    memset(dp, -1, sizeof dp);
    return f(0, 0, 0, k, s);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    while (cin >> n >> k) {
        string s;
        for (; n; n >>= 1) s = char(n % 2 + '0') + s;
        if (!s.size()) s = "0";
        if (k > s.size()) cout << 0 << endl;
        else cout << calc(s) + (k == 1) - (k == 0) << endl;
    }

    cerr << "Run Finished";
}

// https://oj.vnoi.info/problem/binary