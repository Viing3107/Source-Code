/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:05:51 - 21/10/2024

*/

#include                        <iostream>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define MASK(i)                 (1ll << i)
#define BIT(i, n)               (n >> i & 1)
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)

using namespace std;

const int       N           = 22;

int n, a[N][N], dp[MASK(N) + 5], cnt[MASK(N) + 5];

/*

    dp[mask] là tài sản lớn nhất
    cnt[mask] là số cách để có tài sản là dp[mask]

*/

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    forUp(i, 1, n, 1) forUp(j, 1, n, 1) cin >> a[i][j];
    forUp(j, 0, n - 1, 1) {
        dp[MASK(j)] = a[1][j + 1];
        cnt[MASK(j)] = 1;
    }
    forUp(mask, 0, MASK(n) - 1, 1) {
        int i = __builtin_popcount(mask);
        forUp(j, 0, n - 1, 1) if (BIT(j, mask)) {
            if (dp[mask ^ MASK(j)] + a[i][j + 1] > dp[mask]) {
                dp[mask] = dp[mask ^ MASK(j)] + a[i][j + 1];
                cnt[mask] = cnt[mask ^ MASK(j)];
            }
            else if (dp[mask ^ MASK(j)] + a[i][j + 1] == dp[mask]) cnt[mask] += cnt[mask ^ MASK(j)];
        }
    }
    
    cout << dp[MASK(n) - 1] << " " << cnt[MASK(n) - 1];
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/maugiao