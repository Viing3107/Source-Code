#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e4 + 4;
const int M = 1e2 + 2;
const int MOD = 1e9 + 7;

int dp[N][2][M], d, n;
string s;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> s >> d;
    n = s.size();
    s = " " + s;
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int lower = 0; lower <= 1; lower++) {
            for (int mod = 0; mod <= d - 1; mod++) {
                for (int next = 0; next <= 9; next++) {
                    if (!lower && next > s[i + 1] - '0') continue;
                    int lower2 = lower || next < s[i + 1] - '0';

                    int mod2 = (mod + next) % d;

                    (dp[i + 1][lower2][mod2] += dp[i][lower][mod]) %= MOD;
                }
            }
        }
    }

    cout << ((dp[n][0][0] + dp[n][1][0] - 1) % MOD + MOD) % MOD;
}

// https://oj.vnoi.info/problem/atcoder_dp_s