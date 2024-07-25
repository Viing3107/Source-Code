/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 23:20:30 - 25/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define MASK(i)                 (1ll << i)
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e5 + 5;
const int MOD           = 2111992;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, k, dp[N][2];

/*
    gọi dp[i][0] là số cách sắp xếp n con bò, con bò cuối là đực
    gọi dp[i][1] là số cách sắp xếp n con bò, con bò cuối là cái
    Để con bò thứ i là đực thì mọi con bò i - 1, i - 2, ..., i - k là con cái, con bò thứ i - k - 1 có thể là đực hoặc cái : dp[i][0] = dp[i - k - 1][0] + dp[i - k - 1][1]
    Để con bò thứ i là cái thì con bò thứ i - 1 có thể là đực hoặc cái : dp[i][1] = dp[i - 1][0] + dp[i - 1][1]

*/

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> k;
    dp[1][0] = 1;
    dp[1][1] = 1;
    forUp(i, 2, k + 1, 1) {
        dp[i][0] = 1;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }
    forUp(i, k + 2, n, 1) {
        dp[i][0] = (dp[i - k - 1][0] + dp[i - k - 1][1]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }
    cout << (dp[n][0] + dp[n][1]) % MOD;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/ctnbulls