/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 17:21:32 - 26/07/2025

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
#define forEach(it, v)          for (typeof (v).begin() it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int       BASE        = 311;
const int       BLOCK_SIZE  = 320;
const int       N           = 5e5 + 5;
const int       VAL         = 1e6 + 6;
const int       MOD         = 1e9 + 7;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, k, a[N];

struct SparseTable {
    int minVal[N][LOG(N) + 5], maxVal[N][LOG(N) + 5];

    void build() {
        forUp(i, 1, n, 1) {
            minVal[i][0] = a[i];
            maxVal[i][0] = a[i];
        }
        for (int j = 1; MASK(j) <= n; j++) for (int i = 1; i + MASK(j) - 1 <= n; i++) {
            minVal[i][j] = min(minVal[i][j - 1], minVal[i + MASK(j - 1)][j - 1]);
            maxVal[i][j] = max(maxVal[i][j - 1], maxVal[i + MASK(j - 1)][j - 1]);
        }
    }

    int getMin(int l, int r) {
        int k = LOG(r - l + 1);
        return min(minVal[l][k], minVal[r - MASK(k) + 1][k]);
    }

    int getMax(int l, int r) {
        int k = LOG(r - l + 1);
        return max(maxVal[l][k], maxVal[r - MASK(k) + 1][k]);
    }
} st;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> k;
    forUp(i, 1, n, 1) cin >> a[i];
    st.build();
    int l = 1, r = 1, res = 0;
    while (r <= n) {
        while (r <= n && st.getMax(l, r) - st.getMin(l, r) <= k) {
            res += r - l + 1;
            r++;
        }
        l++;
        while (r <= n && st.getMax(l, r) - st.getMin(l, r) > k) l++;
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

// https://oj.vnoi.info/problem/fcb040_kmemory