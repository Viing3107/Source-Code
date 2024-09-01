#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e4 + 4;
const int M = 1e2 + 2;

string a, b;
int k, dp[11][2][N][M], p[11];

/*

dp = {i, lower, num, sum_digit}

*/

int f(int i, int lower, int num, int sum, string s) {
    if (dp[i][lower][num][sum] != -1) return dp[i][lower][num][sum];

    if (i == s.size()) return num == 0 && sum % k == 0;

    int ans = 0;
    for (int next = 0; next <= 9; next++) {
        if (!lower && next > s[i] - '0') continue;
        int lower2 = lower || next < s[i] - '0';

        int num2 = (num * 10 + next) % k;

        int sum2 = sum + next;

        ans += f(i + 1, lower2, num2, sum2, s);
    }

    return dp[i][lower][num][sum] = ans;
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

    cin >> a >> b >> k;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] == '0') a[i] = '9';
        else {
            a[i]--;
            break;
        }
    }
    p[0] = 1;
    for (int i = 1; i <= 10; i++) p[i] = p[i - 1] * 10;
    cout << calc(b) - calc(a);
    
    cerr << "Run Finished";
}

// https://lqdoj.edu.vn/problem/chiahet