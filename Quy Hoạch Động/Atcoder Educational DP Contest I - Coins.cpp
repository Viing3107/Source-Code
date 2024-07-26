/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 10:59:21 - 26/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define MASK(i)                 (1ll << (i))
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 3e3 + 3;
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n;
double p[N], dp[N][N];

/*
    gọi dp[i][cnt] là xác suất tung được cnt mặt sấp, khi xét đến đồng xu thứ i

    dp[1][0] = 1 - p[1]
    dp[1][1] = p[1]

    dp[i][j] = dp[i - 1][j - 1] * (1 - p[i]) + dp[i - 1][j] * p[i]
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
    forUp(i, 1, n, 1) cin >> p[i];
    dp[0][0] = 1;
    dp[1][0] = p[1];
    dp[1][1] = 1 - p[1];
    forUp(i, 1, n, 1) dp[i][0] = dp[i - 1][0] * p[i];
    forUp(i, 2, n, 1) {
        for (int j = 1; j * 2 < n; j++) {
            dp[i][j] = dp[i - 1][j - 1] * (1 - p[i]) + dp[i - 1][j] * p[i];
        }
    }
    // forUp(i, 1, n, 1) {
    //     for (int j = 0; j * 2 < n; j++) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    double res = 0;
    for (int j = 0; j * 2 < n; j++) res += dp[n][j];
    cout << fixed << setprecision(10) << res;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/atcoder_dp_i