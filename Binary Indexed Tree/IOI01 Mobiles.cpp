/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 09:02:43 - 19/09/2025

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
const int       N           = 1030;
const int       VAL         = 1e6 + 6;
const int       MOD         = 1e9 + 7;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int type, n, x, y, u, v, val;

struct FenwickTree2D {
    int ft[N][N];

    void build() {
        memset(ft, 0, sizeof ft);
    }

    void update(int x, int y, int val) {
        for (int i = x; i <= n; i += i & -i) 
            for (int j = y; j <= n; j += j & -j)
                ft[i][j] += val;
    }

    int get(int x, int y) {
        int res = 0;
        for (int i = x; i; i -= i & -i)
            for (int j = y; j; j -= j & -j)
                res += ft[i][j];
        return res;
    }

    int query(int x, int y, int u, int v) {
        return get(u, v) - get(u, y - 1) - get(x - 1, v) + get(x - 1, y - 1);
    }
} bit;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    while (cin >> type) {
        if (!type) {
            cin >> n;
            bit.build();
        }
        else if (type == 1) {
            cin >> x >> y >> val;
            x++;
            y++;
            bit.update(x, y, val);
        }
        else if (type == 2) {
            cin >> x >> y >> u >> v;
            x++;
            y++;
            u++;
            v++;
            cout << bit.query(x, y, u, v) << endl;
        }
        else return 0;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/nkmobile