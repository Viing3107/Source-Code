/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:19:23 - 15/10/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << i)
#define BIT(i, n)               (n >> i & 1)
#define SZ(v)                   (int) v.size()
#define all(v)                  v.begin(), v.end()
#define LOG(x)                  (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof v.begin() it = v.begin(), _e = it.end(); it != _e; it++)

using namespace std;

const int       N           = 20;
const int       MOD         = 1e9 + 7;
const int       LOG         = __lg(N) + 5;
const int       BLOCK_SIZE  = sqrt(N) + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, a[N][N], dp[MASK(N)][N];

/*
    gọi dp[mask][i] là chi phí nhỏ nhất để có trạng thái mask, đỉnh cuối cùng là i
    dp[mask][i] = min(dp[mask - MASK(i)][j] + a[j][i]) 
        với BIT(i, mask) = 1 và BIT(j, mask - MASK(i)) = 1 và i != j

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
    forUp(i, 0, n - 1, 1) forUp(j, 0, n - 1, 1) cin >> a[i][j];
    memset(dp, 0x3f, sizeof dp);
    forUp(i, 0, n - 1, 1) dp[MASK(i)][i] = 0; // đỉnh i chính là đỉnh xuất phát & kết thúc
    forUp(mask, 0, MASK(n) - 1, 1) if (__builtin_popcount(mask) > 1) {
        forUp(i, 0, n - 1, 1) if (BIT(i, mask)) {
            forUp(j, 0, n - 1, 1) if (BIT(j, mask - MASK(i))) dp[mask][i] = min(dp[mask][i], dp[mask - MASK(i)][j] + a[j][i]);
        }
    }
    cout << *min_element(dp[MASK(n) - 1], dp[MASK(n) - 1] + n);
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/lem3