/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define BIT(i, n)               ((n) >> (i) & 1)
#define SZ(v)                   (int) (v).size()
#define ALL(v)                  (v).begin(), (v).end()
#define LOG(x)                  (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof v.begin() it = v.begin(); it != v.end(); it++)

using namespace std;

const int       N           = 1e5 + 5;
const int       BASE        = 31;
const int       MOD         = 1e9 + 7;
const int       BLOCK_SIZE  = sqrt(N) + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, a[N], dp[N], preSum[N];

/*
goi dp[i] là so tien nho nhat khi xet den mon hang thu i
dp[i] = dp[i - 1] + a[i] // mon hang i la mon dau tien cho vao gio hang rieng
dp[i] = min(dp[i], dp[j] + sum(j + 1, i) - min(k, j + 1, i));
        voi +) j < i
            +) sum(j + 1, i) = tong a[j + 1] + a[j + 2] + ... + a[i]
            +) k = (i - j) / 10
            +) min(k, j + 1, i) = k so nho nhat trong doan [j + 1, i]

Nhan xet: khi k = 1 thi toi uu luong tien nhat
--> dp[n]
*/
struct SparseTable {
    int minVal[N][LOG(N) + 5];

    SparseTable() {
        memset(minVal, 0x3f, sizeof minVal);
    }

    void build() {
        forUp (i, 1, n, 1) minVal[i][0] = a[i];
        for (int j = 1; MASK(j) <= n; j++) for (int i = 1; i + MASK(j) - 1 <= n; i++)
            minVal[i][j] = min(minVal[i][j - 1], minVal[i + MASK(j - 1)][j - 1]);
    }

    int get(int l, int r) {
        int k = LOG(r - l + 1);
        return min(minVal[l][k], minVal[r - MASK(k) + 1][k]);
    }
} st;

int get(int l, int r) {return preSum[r] - preSum[l - 1];}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    forUp (i, 1, n, 1) {
        cin >> a[i];
        dp[i] = INF;
        preSum[i] = preSum[i - 1] + a[i];
    }
    st.build();
    dp[1] = a[1];
    forUp (i, 2, n, 1) {
        dp[i] = dp[i - 1] + a[i];
        if (i >= 10) dp[i] = min(dp[i], dp[i - 10] + get(i - 9, i) - st.get(i - 9, i));
    }
    cout << dp[n];

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 Viing3107

*/

// https://oj.vnoi.info/problem/th_thpt_21_e
