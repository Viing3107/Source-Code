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
const int    N          = 2e5 + 5;
const int    VAL        = 1e6 + 6;
const int    MOD        = 1e9 + 7;
const int    INF        = 0x3f3f3f3f3f3f3f3f;

int n, a[N], preSum[N];

struct SparseTable {
    int minVal[N][LOG(N)];

    void build() {
        forUp (i, 1, 2 * n, 1) minVal[i][0] = preSum[i];
        for (int j = 1; MASK(j) <= 2 * n; j++) {
            for (int i = 1; i + MASK(j) - 1 <= 2 * n; i++) 
                minVal[i][j] = min(minVal[i][j - 1], minVal[i + MASK(j - 1)][j - 1]);
        }
    }

    int get(int l, int r) {
        int k = LOG(r - l + 1);
        return min(minVal[l][k], minVal[r - MASK(k) + 1][k]);
    }
} st;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n;
    forUp (i, 1, n, 1) cin >> a[i];
    forUp (i, n + 1, n + n, 1) a[i] = a[i - n];
    forUp (i, 1, 2 * n, 1) preSum[i] = preSum[i - 1] + a[i];
    st.build();
    int res = 0;
    forUp (i, 1, n, 1) res += (preSum[i - 1] < st.get(i, i + n - 1));
    cout << res;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/nkseq