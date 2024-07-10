/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 12:20:03 - 10/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for(int i = (l); i >= (r); i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define endl                    "\n"

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, a[N], dp[N][2];

/*
    gọi dp[i][0] là giá trị lớn nhất khi xét đến vị trí thứ i và không chọn món quà thứ i
    gọi dp[i][1] là giá trị lớn nhất khi xét đến vị trí thứ i và chọn món quà thứ i

    dp[1][1] = a[1]

    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1])
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][1])
    dp[i][1] = max({dp[i][1], dp[i - 1][0] + a[i], dp[i - 2][0] + a[i - 1] + a[i]})
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
    forUp (i, 1, n, 1) cin >> a[i];
    dp[1][1] = a[1];
    forUp (i, 2, n, 1) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = max({dp[i][1], dp[i - 1][0] + a[i], dp[i - 2][0] + a[i - 1] + a[i]});
    }
    // forUp (i, 1, n, 1) cout << dp[i][0] << " " << dp[i][1] << endl;
    cout << max(dp[n][0], dp[n][1]);
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc098_reward