#include <bits/stdc++.h>
#define int long long
#define double long double

using namespace std;

const int N = 1e5 + 5;
const int MOD = 1e9 + 9;
const int INF = 0x3f3f3f3f3f3f3f3f;

string s, t;
int dp[20][2048], result;

int f(int i, int mod, string num, string &s) {
    if (dp[i][mod] != -1) return dp[i][mod];

    if (i == s.size()) return !mod;

    int mod2, ans = 0;
    string num2;

    if (s[i] >= '0' && s[i] <= '9') {
        mod2 = (mod * 10 + (s[i] - '0')) % 2048;

        num2 = num + s[i];

        (ans += f(i + 1, mod2, num2, s)) %= MOD;
    }
    else {
        for (int digit = 0; digit <= 9; digit++) {
            mod2 = (mod * 10 + digit) % 2048;

            num2 = num + char(digit + '0');

            (ans += f(i + 1, mod2, num2, s)) %= MOD;
        }
    }

    return dp[i][mod] = ans;
}

int calc(string s) {
    memset(dp, -1, sizeof dp);
    return f(0, 0, "", s);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> s;
    while (s.size() < 11) s = '0' + s;
    t = s.substr(s.size() - 11, 11);
    result = calc(t);
    for (int i = 0; i + 11 < s.size(); i++) if (s[i] == '?') (result *= 10) %= MOD;
    cout << result;
}

// https://oj.vnoi.info/problem/bedao_r13_2048
