#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4;
const int MOD = 1e9 + 7;

int dp[N][2][3];

/*

dp = {i, lower, mod}

*/

string n;

int f(int i, int lower, int mod, string s) {
    if (dp[i][lower][mod] != -1) return dp[i][lower][mod];

    if (i == s.size()) return mod == 0;

    int ans = 0;
    for (int next = 0; next <= 9; next++) {
        if (!lower && next > s[i] - '0') continue;
        int lower2 = lower || next < s[i] - '0';

        int mod2 = (mod + next * next) % 3;

        (ans += f(i + 1, lower2, mod2, s)) %= MOD;
    }

    return dp[i][lower][mod] = ans;
}

int calc(string &x) {
    memset(dp, -1, sizeof dp);
    return f(0, 0, 0, x);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n;
    for (int i = n.size() - 1; i >= 0; i--) {
        if (n[i] == '0') n[i] = '9';
        else {
            n[i]--;
            break;
        }
    }
    cout << calc(n);
}

// https://lqdoj.edu.vn/problem/sqamod