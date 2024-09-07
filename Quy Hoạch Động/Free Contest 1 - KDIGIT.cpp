#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 22;

int d, K, dp[N][2][2][N][N][10];
string A, B;

int f(int i, int lower, int positive, int maxfre, int k, int last, string &s) {
    if (dp[i][lower][positive][maxfre][k][last] != -1) return dp[i][lower][positive][maxfre][k][last];

    if (i == s.size()) return maxfre >= K;

    int ans = 0;
    for (int digit = 0; digit <= 9; digit++) {
        if (!lower && digit > s[i] - '0') continue;
        int lower2 = lower || digit < s[i] - '0';

        int positive2 = positive || digit > 0;

        int k2 = k;
        if (positive2) {
            if (positive && digit == last) k2++;
            else k2 = 1;
        }

        int maxfre2 = max(maxfre, k2);

        ans += f(i + 1, lower2, positive2, maxfre2, k2, digit, s);
    }
    return dp[i][lower][positive][maxfre][k][last] = ans;
}

int calc(string s) {
    memset(dp, -1, sizeof dp);
    return f(0, 0, 0, 0, 0, 0, s);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> A >> B >> K;
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] == '0') A[i] = '9';
        else {
            A[i]--;
            break;
        }
    }
    cout << calc(B) - calc(A);

    cerr << "Run Finished";
}

// https://oj.vnoi.info/problem/fc001_kdigit