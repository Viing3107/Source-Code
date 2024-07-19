/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 13:38:00 - 19/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define mask(a)                 (1ll << a)
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e5 + 5;
const int PRIME_SIZE    = 9593;
const int LOG           = __lg(N);
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, a[N], minLength = INF, L, R;

struct SparseTable{
    int GCD[N][LOG + 5];

    void build() {
        forUp(i, 1, n, 1) GCD[i][0] = a[i];
        for (int j = 1; mask(j) <= n; j++) {
            for (int i = 1; i + mask(j) - 1 <= n; i++) {
                GCD[i][j] = __gcd(GCD[i][j - 1], GCD[i + mask(j - 1)][j - 1]);
            }
        }
    }

    int get(int l, int r) {
        int length = __lg(r - l);
        return __gcd(GCD[l][length], GCD[r - mask(length) + 1][length]);
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

    cin >> n;
    forUp(i, 1, n, 1) cin >> a[i];
    st.build();
    forUp(i, 1, n, 1) {
        int l = i + 1, r = n, result = INF;
        while (r - l >= 0) {
            int m = l + r >> 1;
            if (st.get(i, m) == 1) {
                result = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        if (result != INF && result - i + 1 < minLength) {
            minLength = result - i + 1;
            L = i;
            R = result;
        }
    }
    if (minLength == INF) cout << -1;
    else cout << minLength << " " << L << " " << R;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc125_gcdarr