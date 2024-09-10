#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

const int N = 1e2 + 2;

int n, k;
int dp[70][70][N];
int p[70];

int f(int i, int cnt, int mod, string num) {
    if (dp[i][cnt][mod] != -1) return dp[i][cnt][mod];

    if (i == n) return !mod && cnt == n / 2;

    int ans = 0;
    for (int digit = 0; digit <= 1; digit++) {
        if (!i && !digit) continue;

        int cnt2 = cnt + (digit == 1);

        int diff = (digit * p[n - i - 1]) % k;
        int mod2 = (mod + diff) % k;

        string num2 = num + char(digit + '0');

        ans += f(i + 1, cnt2, mod2, num2);
    }

    return dp[i][cnt][mod] = ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    p[0] = 1;
    for (int i = 1; i <= 63; i++) p[i] = p[i - 1] * 2;
    cin >> n >> k;
    if (!k || n & 1) cout << 0;
    else {
        for (int i = 0; i <= 65; i++) {
            for (int cnt = 0; cnt <= 65; cnt++) {
                for (int mod = 0; mod <= 100; mod++) dp[i][cnt][mod] = -1;
            }
        }
        cout << fixed << setprecision(0) << f(0, 0, 0, "");
    }

    cerr << "Run Finished";
}

// https://oj.vnoi.info/problem/fc026_010101
