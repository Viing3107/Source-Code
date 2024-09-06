#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 20;
const int MAX = 9 * N;
const int SQRMAX = 1666;

int dp[N][2][MAX][SQRMAX];
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

int f(int i, int lower, int sum, int sqrsum, string &s) {
    if (dp[i][lower][sum][sqrsum] != -1) return dp[i][lower][sum][sqrsum];

    if (i == s.size()) return isPrime(sum) && isPrime(sqrsum);

    int ans = 0;
    for (int next = 0; next <= 9; next++) {
        if (!lower && next > s[i] - '0') continue;
        int lower2 = lower || next < s[i] - '0';

        int sum2 = sum + next;

        int sqrsum2 = sqrsum + next * next;

        ans += f(i + 1, lower2, sum2, sqrsum2, s);
    }

    return dp[i][lower][sum][sqrsum] = ans;
}

int calc(string s) {
    memset(dp, -1, sizeof dp);
    return f(0, 0, 0, 0, s);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("ANHEM.inp", "r", stdin);
    freopen("ANHEM.out", "w", stdout);

    sieve(2000);
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

// https://lqdoj.edu.vn/problem/23ts10dna1