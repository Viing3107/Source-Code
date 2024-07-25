/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:26:04 - 25/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define MASK(i)                 (1ll << i)
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e4 + 4;
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;
const int LOG           = __lg(N) + 5;

int n, k, a[N], dp[N];

/*
    gọi dp[i] là kĩ năng gói quà lớn nhất khi xét đến chú bò thứ i

    dp[i] = *max_element(a + 1, a + i + 1) nếu i <= k
    dp[i] = max(dp[j], *max_element(a + j + 1, a + i + 1) * (i - j)) với mọi k <= j < i

    đáp án : dp[n]
*/

struct SparseTable{
    int maxVal[N][LOG];

    void build() {
        forUp(i, 1, n, 1) maxVal[i][0] = a[i];
        for (int j = 1; MASK(j) <= n; j++) {
            for (int i = 1; i + MASK(j) - 1 <= n; i++) maxVal[i][j] = max(maxVal[i][j - 1], maxVal[i + MASK(j - 1)][j - 1]);
        }
    }

    int get(int l, int r) {
        int k = __lg(r - l + 1);
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
    for (int i = 1; i <= k; i++) dp[i] = st.get(1, i) * i;
    forUp(i, k + 1, n, 1) {
        forUp(j, i - k, i - 1, 1) dp[i] = max(dp[i], dp[j] + st.get(j + 1, i) * (i - j));
    }
    cout << dp[n] << endl;
    // forUp(i, 1, n, 1) cout << dp[i] << " ";
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/usaco18dg_teamwork
