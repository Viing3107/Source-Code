/*
    Author : Do Quang Vinh
    Vietnam National University - Ha Noi
    Created : 17:52:19 - 21/11/2025

*/

#include <bits/stdc++.h>
#define endl                   "\n"
#define task                   "test"
#define int                    long long
#define double                 long double
#define gcd(x, y)              __gcd(x, y)
#define MASK(i)                (1ll << (i))
#define BIT(i, n)              ((n) >> (i) & 1)
#define SZ(v)                  (int)(v).size()
#define lcm(x, y)              x / gcd(x, y) * y
#define ALL(v)                 (v).begin(), (v).end()
#define LOG(x)                 (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)   for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step) for (int i = (l); i >= (r); i += step)

using namespace std;

const int    LEVEL      = 20;
const int    BASE       = 311;
const int    BLOCK_SIZE = 320;
const double EPS        = 1e-6;
const int    N          = 3e5 + 5;
const int    VAL        = 1e6 + 6;
const int    MOD        = 1e9 + 7;
const int    INF        = 0x3f3f3f3f3f3f3f3f;

/* 
gọi dp[0][i] là giá trị lớn nhất của đoạn con liên tiếp kết thúc tại i (chưa nhân x)
gọi dp[1][i] là giá trị lớn nhất của đoạn con liên tiếp kết thúc tại i (đang nhân x)
gọi dp[2][i] là giá trị lớn nhất của đoạn con liên tiếp kết thúc tại i (đã nhân x)
tại vị trí i:
    - dp[0][i] = max(dp[0][i - 1] + a[i], a[i])
    - dp[1][i] = max(dp[0][i - 1] + a[i] * x, dp[1][i - 1] + a[i] * x, a[i] * x)
    - dp[2][i] = max(dp[2][i - 1] + a[i], dp[1][i - 1] + a[i], a[i])
*/
int n, x, a[N], dp[3][N], res = -INF;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> x;
    forUp (i, 1, n, 1) cin >> a[i];
    forUp (i, 1, n, 1) {
        dp[0][i] = max(dp[0][i - 1] + a[i], a[i]);
        dp[1][i] = max({dp[0][i - 1] + a[i] * x, dp[1][i - 1] + a[i] * x, a[i] * x});
        dp[2][i] = max({dp[2][i - 1] + a[i], dp[1][i - 1] + a[i], a[i]});
        res = max({res, dp[0][i], dp[1][i], dp[2][i]});
    }
    cout << res;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/bedao_m27_c
// https://oj.vnoi.info/problem/fc108_dpc7
// https://oj.vnoi.info/problem/dtqna_kadanepp