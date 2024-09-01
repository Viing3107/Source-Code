#include <bits/stdc++.h>

using namespace std;

const int N = 10;
const int M = 1e2 + 2;

int dp[N][2][M], n;

/*

dp = {i, lower, sum}

*/

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

int f(int i, int lower, int sum, string s) {
    if (dp[i][lower][sum] != -1) return dp[i][lower][sum];

    if (i == s.size()) return isPrime(sum);

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

    sieve(100);
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] == '9') a[i] = '0';
        else {
            a[i]--;
            break;
        }
    }
    cout << calc(b) - calc(a);
}

// https://lqdoj.edu.vn/problem/gone