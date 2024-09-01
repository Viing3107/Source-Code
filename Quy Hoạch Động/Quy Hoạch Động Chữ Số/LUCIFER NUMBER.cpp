#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4;
const int M = 1e2 + 2;

string a, b;
int dp[10][2][M][M];
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

int f(int i, int lower, int even, int odd, string &s) {
    if (dp[i][lower][even][odd] != -1) return dp[i][lower][even][odd];

    if (i == s.size()) return isPrime(even - odd);

    int ans = 0;
    for (int next = 0; next <= 9; next++) {
        if (!lower && next > s[i] - '0') continue;
        int lower2 = lower || next < s[i] - '0';

        int even2 = even, odd2 = odd;
        if (s.size() - i & 1) odd2 += next;
        else even2 += next;

        ans += f(i + 1, lower2, even2, odd2, s);
    }
    return dp[i][lower][even][odd] = ans;
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

    sieve(M);
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

// https://lqdoj.edu.vn/problem/lucifer