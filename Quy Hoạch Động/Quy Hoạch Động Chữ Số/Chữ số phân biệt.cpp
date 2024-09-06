#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 20;
const int MAX = (1ll << 11);

int dp[N][2][MAX];
string a, b;

int f(int i, int lower, int positive, int mask, string &s) {
    if (dp[i][lower][mask] != -1) return dp[i][lower][mask];

    if (i == s.size()) return 1;

    int ans = 0;
    for (int next = 0; next <= 9; next++) {
        if (!lower && next > s[i] - '0') continue;
        int lower2 = lower || next < s[i] - '0';

        int positive2 = positive || next > 0;

        int mask2 = mask;
        if (positive2) {
            if (mask >> next & 1) continue;
            mask2 |= (1ll << next);
        }

        ans += f(i + 1, lower2, positive2, mask2, s);
    }

    return dp[i][lower][mask] = ans;
}

int calc(string s) {
    memset(dp, -1, sizeof dp);
    return f(0, 0, 0, 0, s);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] == '0') a[i] = '9';
        else {
            a[i]--;
            break;
        }
    }
    cout << calc(b) - calc(a);
}

// https://lqdoj.edu.vn/problem/cspb