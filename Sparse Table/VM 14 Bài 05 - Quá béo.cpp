/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:35:45 - 26/07/2025

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
const int       N           = 1e6 + 5;
const int       VAL         = 1e6 + 6;
const int       MOD         = 1e9 + 7;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, l, d, h[N];

struct SparseTable {
    int minVal[N][LOG(N) + 5], maxVal[N][LOG(N) + 5];

    void build() {
        forUp(i, 1, n, 1) minVal[i][0] = maxVal[i][0] = h[i];
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

    cin >> n >> l >> d;
    l++;
    forUp(i, 1, n, 1) cin >> h[i];
    st.build();
    int i = 1, j = l, res = 0;
    while (j <= n) {
        while (j - i + 1 < l && j <= n) j++;
        while (j <= n && st.getMax(i, j) - st.getMin(i, j) <= d) {
            res += max(0ll, (j - l + 1) - i + 1);
            j++;
        }
        i++;
        while (j - i + 1 >= l && j <= n && st.getMax(i, j) - st.getMin(i, j) > d) i++;
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

// https://oj.vnoi.info/problem/vmquabeo