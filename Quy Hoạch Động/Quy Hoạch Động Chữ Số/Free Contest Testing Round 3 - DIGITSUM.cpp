#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 20;
const int M = 9 * 20;

int dp[N][2][M], n;

/*

dp = {i, lower, sum}

*/

string a, b;

int f(int i, int lower, int sum, string s) {
    if (dp[i][lower][sum] != -1) return dp[i][lower][sum];

    if (i == s.size()) return sum;

    int ans = 0;
    for (int next = 0; next <= 9; next++) {
        if (!lower && next > s[i] - '0') continue;
        int lower2 = lower || next < s[i] - '0';

        int sum2 = sum + next;

        ans += f(i + 1, lower2, sum2, s);
    }

    return dp[i][lower][sum] = ans;
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

    cin >> a >> b;
    if (a == "0") cout << calc(b);
    else {
        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] == '0') a[i] = '9';
            else {
                a[i]--;
                break;
            }
        }
        cout << calc(b) - calc(a);
    }
}

// https://oj.vnoi.info/problem/fct003_digitsum