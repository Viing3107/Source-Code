/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:08:55 - 05/08/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define SZ(v)                   (int) v.size()
#define all(v)                  v.begin(), v.end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 5e2 + 2;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, dp[N][N];

/*

gọi dp[i][j] là số cầu thang có i viện gạch và bậc cuối cùng có j viên gạch
dp[i][j] = tổng(dp[i - j][u]) với mọi u < j

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
    forUp(i, 1, n, 1) dp[i][i] = 1;
    forUp(i, 1, n, 1) {
        forUp(j, 1, i - 1, 1) {
            forUp(u, 1, min(j - 1, i - j), 1) {
                dp[i][j] += dp[i - j][u];
            }
        }
    }
    // forUp(i, 1, n, 1) {
    //     forUp(j, 1, n, 1) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    int result = 0;
    forUp(i, 1, n, 1) result += dp[n][i];
    cout << result - 1;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc030_stair