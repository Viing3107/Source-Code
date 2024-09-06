#include <bits/stdc++.h>

using namespace std;

const int N = 11;
const int MAX = 1 << N;

string s, result;
int dp[N][2][MAX];

void f(int i, int greater, int mask, int positive, string num, string &s) {
    if (dp[i][greater][mask]) return;

    dp[i][greater][mask] = 1;

    if (i == s.size()) {
        if (result == "0") result = num;
        return;
    }

    for (int next = 1; next <= 9; next++) {
        if (!greater && next < s[i] - '0') continue;
        int greater2 = greater || next > s[i] - '0';

        if (mask >> next & 1) continue;
        int mask2 = mask | (1 << next);

        int positive2 = positive || next > 0;

        string num2 = num;
        if (positive2) num2 += char(next + '0');

        f(i + 1, greater2, mask2, positive2, num2, s);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    while (cin >> s) {
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '9') s[i] = '0';
            else {
                s[i]++;
                break;
            }
        }
        if (s[0] == '0') s = '1' + s;
        memset(dp, 0, sizeof dp);
        result = "0";
        f(0, 0, 0, 0, "", s);
        s = '0' + s;
        memset(dp, 0, sizeof dp);
        f(0, 0, 0, 0, "", s);
        if (result == "") result = "0";
        cout << result << "\n";
    }
    
}

// https://oj.vnoi.info/problem/hspc14l