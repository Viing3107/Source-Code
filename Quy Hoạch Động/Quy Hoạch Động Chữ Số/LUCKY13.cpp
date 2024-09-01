#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 20;

string a, b;
int n, m, dp[N][2][10];

int f(int i, int lower, int lastDigit, string &s) {
    if (dp[i][lower][lastDigit] != -1) return dp[i][lower][lastDigit];

    if (i == s.size()) return 1;

    int ans = 0;
    for (int next = 0; next <= 9; next++) {
        if (lastDigit == 1 && next == 3) continue;
        int lastDigit2 = next;

        if (!lower && next > s[i] - '0') continue;
        int lower2 = lower || next < s[i] - '0';

        ans += f(i + 1, lower2, lastDigit2, s);
    }
    return dp[i][lower][lastDigit] = ans;
}

int calc(string &s) {
    memset(dp, -1, sizeof dp);
    return f(0, 0, 0, s);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    while (cin >> a >> b) {
        if (a == "0") cout << calc(b) << "\n";
        else {
            for (int i = a.size() - 1; i >= 0; i--) {
                if (a[i] == '0') a[i] = '9';
                else {
                    a[i]--;
                    break;
                }
            }
            cout << calc(b) - calc(a) << "\n";
        }    
    }
    
    cerr << "Run Finished";
}

// https://oj.vnoi.info/problem/lucky13