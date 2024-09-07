#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 20;

int d, k, dp[N][2][2][N][10];
string a, b;

int f(int i, int lower, int positive, int k, int last, string &s) {
    if (k < 0) return 0;

    if (dp[i][lower][positive][k][last] != -1) return dp[i][lower][positive][k][last];

    if (i == s.size()) return k >= 0;

    int ans = 0;
    for (int digit = 0; digit <= 9; digit++) {
        if (!lower && digit > s[i] - '0') continue;
        int lower2 = lower || digit < s[i] - '0';

        int positive2 = positive || digit > 0;

        int k2 = k;
        if (positive && positive2) k2 -= abs(digit - last) <= d;

        int last2 = digit;

        ans += f(i + 1, lower2, positive2, k2, last2, s);
    }
    return dp[i][lower][positive][k][last] = ans;
}

int calc(string s) {
    memset(dp, -1, sizeof dp);
    return f(0, 0, 0, k, 0, s);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> a >> b >> d >> k;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] == '0') a[i] = '9';
        else {
            a[i]--;
            break;
        }
    }
    cout << calc(b) - calc(a);

    cerr << "Run Finished";
}

// https://oj.vnoi.info/problem/demso