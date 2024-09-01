#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 200;
const int M = 1600;

string a, b;
int dp[20][2][N][M];

int f(int i, int lower, int sumDigit, int sqrDigit, string &s) {
    if (dp[i][lower][sumDigit][sqrDigit] != -1) return dp[i][lower][sumDigit][sqrDigit];

    if (i == s.size()) return __gcd(sumDigit, sqrDigit) == 1;

    int ans = 0;
    for (int next = 0; next <= 9; next++) {
        if (!lower && next > s[i] - '0') continue;
        int lower2 = lower || next < s[i] - '0';

        int sumDigit2 = sumDigit + next;

        int sqrDigit2 = sqrDigit + next * next;

        ans += f(i + 1, lower2, sumDigit2, sqrDigit2, s);
    }
    return dp[i][lower][sumDigit][sqrDigit] = ans;
}

int calc(string &s) {
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
    
    cerr << "Run Finished";
}

// https://lqdoj.edu.vn/problem/sbt