/*
    Author: Do Quang Vinh
    VNU University of Engineering and Technology, Hanoi, Vietnam
    Created: 23:28:51 20/08/2026

*/

#include <bits/stdc++.h>
#define endl                   "\n"
#define task                   "test"
#define int                    long long
#define double                 long double
#define MASK(i)                (1ll << (i))
#define SZ(v)                  (int)(v).size()
#define BIT(i, n)              ((n) >> (i) & 1)
#define lcm(x, y)              x / gcd(x, y) * y
#define ALL(v)                 (v).begin(), (v).end()
#define LOG(x)                 (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)   for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step) for (int i = (l); i >= (r); i += step)

using namespace std;

const int    LEVEL      = 20;
const int    BASE       = 311;
const int    BLOCK_SIZE = 320;
const double EPS        = 1e-6;
const int    N          = 2e5 + 5;
const int    VAL        = 1e6 + 6;
const int    MOD        = 1e9 + 7;
const int    INF        = 0x3f3f3f3f3f3f3f3f;

int n, q, d[N];

int gcd(int a, int b) {
    if (a < 0) a = abs(a);
    if (b < 0) b = abs(b);
    if (a > b) swap(a, b);
    if (!a) return b;
    return gcd(b % a, a);
}

struct FenwickTree {
    int ft[N];

    void update(int idx, int val) {
        for (int i = idx; i <= n; i += i & -i) ft[i] += val;
    }

    int get(int idx) {
        int res = 0;
        for (int i = idx; i >= 1; i -= i & -i) res += ft[i];
        return res;
    }
} bit;

struct SegmentTree {
    int st[4 * N];

    void update(int id, int l, int r, int idx, int val) {
        if (r < idx || l > idx) return;
        if (l == r) return void(st[id] += val);
        int m = l + r >> 1;
        update(id * 2, l, m, idx, val);
        update(id * 2 + 1, m + 1, r, idx, val);
        st[id] = gcd(st[id * 2], st[id * 2 + 1]);
    }

    int get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return 0;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        return gcd(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
    }
} it;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> q;

    while (q--) {
        int type, l, r, x;
        cin >> type;
        if (type == 1) {
            cin >> l >> r >> x;
            it.update(1, 1, n, l, x);
            it.update(1, 1, n, r + 1, -x);
            bit.update(l, x);
            bit.update(r + 1, -x);
        }
        else {
            cin >> l >> r;
            cout << gcd(1 + bit.get(l), it.get(1, 1, n, l + 1, r)) << endl;
        }
    }

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    />0   \>1
*/

// https://oj.vnoi.info/problem/prefixsum_diff_s