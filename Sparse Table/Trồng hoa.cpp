/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 20:17:47 - 01/08/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define MASK(i)                 (1ll << (i))
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 3e5 + 5;
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;
const int LOG           = __lg(N) + 5;

int n, k, a[N], dp[N], maxSuf[N], result;

/*
    gọi dp[i] là độ dài khóm hoa dài nhất khi bắt đầu chọn từ bông hoa i
    dp[i] = x lớn nhất thỏa max(i, x) - min(i, x) <= k
    
    gọi maxSuf[i] là giá trị lớn nhất của dp[i..n]
    maxSuf[i] = max(maxSuf[i + 1], dp[i])
    đáp án : max(dp[i] + maxSuf[i + 1])

*/

struct SparseTable {
    int minVal[N][LOG], maxVal[N][LOG];

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

    int get(int l, int r, int state) {
        int k = __lg(r - l + 1);
        if (state) return max(maxVal[l][k], maxVal[r - MASK(k) + 1][k]);
        return min(minVal[l][k], minVal[r - MASK(k) + 1][k]);
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
    forDown(i, n, 1, -1) {
        int l = i, r = n, idx = i;
        while (r - l >= 0) {
            int m = l + r >> 1;
            if (st.get(i, m, 1) - st.get(i, m, 0) <= k) {
                idx = m;
                l = m + 1;
            }
            else r = m - 1;
        }
        dp[i] = idx - i + 1;
        maxSuf[i] = max(maxSuf[i + 1], dp[i]);
    }
    // forUp(i, 1, n, 1) cout << dp[i] << " ";
    // cout << endl;
    forUp(i, 1, n, 1) result = max(result, dp[i] + maxSuf[min(n + 1, i + dp[i])]);
    cout << result;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/kdiff