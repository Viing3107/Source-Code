/*
    Author : Do Quang Vinh
    Vietnam National University - Ha Noi
    Created : 17:52:19 - 21/11/2025

*/

#include <bits/stdc++.h>
#define endl                   "\n"
#define task                   "test"
#define int                    long long
#define double                 long double
#define gcd(x, y)              __gcd(x, y)
#define MASK(i)                (1ll << (i))
#define BIT(i, n)              ((n) >> (i) & 1)
#define SZ(v)                  (int)(v).size()
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
const int    N          = 3e5 + 5;
const int    VAL        = 1e6 + 6;
const int    MOD        = 1e9 + 7;
const int    INF        = 0x3f3f3f3f3f3f3f3f;

int n;

struct String {
    string s;
    int id;

    friend bool operator < (String &u, String &v) {
        return u.s < v.s;
    }
} a[N];

struct SegmentTree {
    int st[4 * N];

    void update(int id, int l, int r, int idx) {
        if (idx < l || idx > r) return;
        if (l == r) {
            st[id]++;
            return;
        }
        int m = l + r >> 1;
        update(id * 2, l, m, idx);
        update(id * 2 + 1, m + 1, r, idx);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    int get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return 0;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
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

    cin >> n;
    forUp (i, 1, n, 1) cin >> a[i].s;
    sort(a + 1, a + n + 1);
    forUp (i, 1, n, 1) a[i].id = i;

    forUp (i, 1, n, 1) reverse(ALL(a[i].s));
    sort(a + 1, a + n + 1);
    
    // forUp (i, 1, n, 1) cout << a[i].id << " \n"[i == n];

    int res = 0;
    forDown(i, n, 1, -1) {
        res += it.get(1, 1, n, 1, a[i].id - 1);
        it.update(1, 1, n, a[i].id);
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

// https://oj.vnoi.info/problem/mchaos