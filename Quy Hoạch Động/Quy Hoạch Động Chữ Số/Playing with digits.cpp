#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 12;
const int M = 100;
const int MOD = 4e3 + 3;

int dp[N][2][M][MOD], k;
string a, b;
vector<int> prime, lpf;

void sieve(int n) {
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);
    for (int x = 3; x <= n; x += 2) {
        if (lpf[x] == 2) prime.push_back(lpf[x] = x);
        for (int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; i++)
            lpf[prime[i] * x] = prime[i];
    }
}

bool isPrime(int n) {
    return n >= 2 && lpf[n] == n;
}

int f(int i, int lower, int sum, int mod, string &s) {
    if (dp[i][lower][sum][mod] != -1) return dp[i][lower][sum][mod];

    if (i == s.size()) return isPrime(sum) && !mod;

    int ans = 0;
    for (int next = 0; next <= 9; next++) {
        if (!lower && next > s[i] - '0') continue;
        int lower2 = lower || next < s[i] - '0';

        int sum2 = sum + next;

        int mod2 = (mod * 10 + next) % k;

        ans += f(i + 1, lower2, sum2, mod2, s);
    }

    return dp[i][lower][sum][mod] = ans;
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

    sieve(M);
    cin >> a >> b >> k;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] == '0') a[i] = '9';
        else {
            a[i]--;
            break;
        }
    }
    cout << calc(b) - calc(a);
}

// https://lqdoj.edu.vn/problem/tntchk