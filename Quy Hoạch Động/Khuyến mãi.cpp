/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:38:36 - 07/08/2024

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

const int N             = 1e3 + 3;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, a[N], dp[N][N];

/*

gọi dp[i][j] là số tiền lớn nhất phải trả khi xét đến sản phẩm i và còn j phiếu giảm giá
không sử dụng phiếu giảm giá
    a[i] <= 100
        dp[i][j] = dp[i - 1][j] + a[i]
    ngược lại
        dp[i][j] = dp[i - 1][j - 1] + a[i]
sử dụng phiếu giảm giá
    dp[i][j] = dp[i - 1][j + 1]
dp[i][j] sẽ là phương án nhỏ nhất trong các TH trên

đáp án : min(dp[n][i]) với mọi 0 <= i <= n

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
    forUp(i, 1, n, 1) cin >> a[i];
    memset(dp, 0x3f, sizeof dp);
    forUp(j, 0, n + 1, 1) {
        if (a[1] <= 100) dp[1][0] = a[1];
        else dp[1][1] = a[1];
    }
    forUp(i, 2, n, 1) forUp(j, 0, i, 1) {
        if (a[i] <= 100) dp[i][j] = dp[i - 1][j] + a[i];
        else dp[i][j] = dp[i - 1][j - 1] + a[i];
        dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
    }
    cout << *min_element(dp[n], dp[n] + n + 1);
    // forUp(i, 1, n, 1) {
    //     forUp(j, 0, i, 1) cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/c11km