/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 17:36:43 - 13/08/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define SZ(v)                   (int) v.size()
#define all(v)                  v.begin(), v.end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 5e2 + 2;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int BLOCK_SIZE    = sqrt(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, a[N][N], q;

struct PrefixSum {
    int black[N][N], white[N][N];

    void build() {
        forUp(i, 1, n, 1) forUp(j, 1, n, 1) {
            black[i][j] = black[i - 1][j] + black[i][j - 1] - black[i - 1][j - 1];
            white[i][j] = white[i - 1][j] + white[i][j - 1] - white[i - 1][j - 1];
            if (i + j & 1) black[i][j] += a[i][j];
            else white[i][j] += a[i][j];
        }
    }

    int get(int i1, int j1, int i2, int j2, int state) {
        return state ? black[i2][j2] - black[i2][j1 - 1] - black[i1 - 1][j2] + black[i1 - 1][j1 - 1] : white[i2][j2] - white[i2][j1 - 1] - white[i1 - 1][j2] + white[i1 - 1][j1 - 1];
    }
} prf;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    forUp(i, 1, n, 1) forUp(j, 1, n, 1) cin >> a[i][j];
    prf.build();
    cin >> q;
    while (q--) {
        int x, y, z, t;
        cin >> x >> y >> z >> t;
        cout << abs(prf.get(x, y, z, t, 1) - prf.get(x, y, z, t, 0)) << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/vboard