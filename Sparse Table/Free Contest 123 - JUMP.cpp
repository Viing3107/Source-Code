/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 20:26:03 - 04/08/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << i)
#define SZ(v)                   (int) v.size()
#define all(v)                  v.begin(), v.end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e5 + 5;
const int LOG           = __lg(N) + 5;
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, q, a[N], dp[N];

/*

gọi dp[i] là độ dài lớn nhất khi bắt đầu nhảy từ ngọn núi i
for (i : n -> 1) 
	với mỗi i ta cần tìm vị trí nhỏ nhất lớn hơn i (tạm gọi là j) thỏa mãn a[i] < a[j]
	khi đó dp[i] = dp[j] + 1

*/

struct SparseTable {
    int maxVal[N][LOG];

    void build() {
        forUp(i, 1, n, 1) maxVal[i][0] = a[i];
        for (int j = 1; MASK(j) <= n; j++) for (int i = 1; i + MASK(j) - 1 <= n; i++)
            maxVal[i][j] = max(maxVal[i][j - 1], maxVal[i + MASK(j - 1)][j - 1]);
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

    cin >> n >> q;
    forUp(i, 1, n, 1) cin >> a[i];
    st.build();
    forDown(i, n - 1, 1, -1) {
        int l = i + 1, r = n, idx = 0;
        while (r - l >= 0) {
            int m = l + r >> 1;
            if (st.get(i + 1, m) > a[i]) {
                idx = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        if (idx) {
            dp[i] = dp[idx] + 1;
        }
    }
    // forUp(i, 1, n, 1) cout << dp[i] << " ";
    while (q--) {
        int x;
        cin >> x;
        cout << dp[x] << endl;
    }

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc123_jump