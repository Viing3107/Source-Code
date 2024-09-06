#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 2;
const int M = 9 * N;

string operator + (string u, string v) {
    while (u.size() < v.size()) u = '0' + u;
    while (v.size() < u.size()) v = '0' + v;
    string res = "";
    int carry = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        int val = (u[i] - '0') + (v[i] - '0') + carry;
        res = char(val % 10 + '0') + res;
        carry = val / 10;
    }
    if (carry) res = char(carry + '0') + res;
    return res;
}

string s, dp[N][2][M];

string f(int i, int lower, int sum, string &s) {
    if (dp[i][lower][sum] != "-1") return dp[i][lower][sum];

    if (i == s.size()) return to_string(sum);

    string ans = "";
    for (int next = 0; next <= 9; next++) {
        if (!lower && next > s[i] - '0') continue;
        int lower2 = lower || next < s[i] - '0';

        int sum2 = sum + next;

        ans = ans + f(i + 1, lower2, sum2, s);
    }

    return dp[i][lower][sum] = ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> s;
    for (int i = 0; i <= 101; i++) {
        for (int lower = 0; lower <= 1; lower++) {
            for (int sum = 0; sum <= 9 * 101; sum++) dp[i][lower][sum] = "-1";
        }
    }
    cout << f(0, 0, 0, s);
}

// https://oj.vnoi.info/problem/spsum