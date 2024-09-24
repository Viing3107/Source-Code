#include <bits/stdc++.h>
#define int long long
#define MASK(i) (1ll << i)


using namespace std;

const int N = 1e5 + 5;
const int LOG = __lg(N) + 5;

int n, a[N], maxLength;

struct SparseTable {
    int minVal[N][LOG];

    void build() {
        for (int i = 1; i <= n; i++) minVal[i][0] = a[i];
        for (int j = 1; MASK(j) <= n; j++) for (int i = 1; i + MASK(j) - 1 <= n; i++)
            minVal[i][j] = min(minVal[i][j - 1], minVal[i + MASK(j - 1)][j - 1]);
    }

    int get(int l, int r) {
        int k = __lg(r - l + 1);
        return min(minVal[l][k], minVal[r - MASK(k) + 1][k]);
    }
} st;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
//    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
    st.build();
    for (int i = n; i >= 1; i--) {
        int l = i, r = n, idx;
        while (r - l >= 0) {
            int m = l + r >> 1;
            if (st.get(i, m) >= 1 - i) {
                idx = m;
                l = m + 1;
            }
            else r = m - 1;
        }
        maxLength = max(maxLength, idx - i + 1);
    }
    cout << maxLength;
}

// https://oj.vnoi.info/problem/fct020_seq51
