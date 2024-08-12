/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 12:34:01 - 12/08/2024

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

const int N             = 1e5 + 5;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int BLOCK_SIZE    = sqrt(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, q;

struct SegmentTree {
    int st[4 * N], lazy[4 * N][2];

    void push(int id, int l, int r, int m) {
        (st[id * 2] += ((m - l + 1) * lazy[id][0]) % MOD) %= MOD;
        (st[id * 2] += ((m + l) * (m - l + 1) / 2 * lazy[id][1]) % MOD) %= MOD;
        (st[id * 2 + 1] += ((r - m) * lazy[id][0]) % MOD) %= MOD;
        (st[id * 2 + 1] += ((r + m + 1) * (r - m) / 2 * lazy[id][1]) % MOD) %= MOD;
        (lazy[id * 2][0] += lazy[id][0]) %= MOD;
        (lazy[id * 2 + 1][0] += lazy[id][0]) %= MOD;
        lazy[id][0] = 0;
        (lazy[id * 2][1] += lazy[id][1]) %= MOD;
        (lazy[id * 2 + 1][1] += lazy[id][1]) %= MOD;
        lazy[id][1] = 0;
    }

    void update(int id, int l, int r, int u, int v, int a, int b) {
        if (r < u || l > v) return;
        if (u <= l && r <= v) {
            (((st[id] += (r - l + 1) * (b - a * u)) %= MOD) += MOD) %= MOD;
            (st[id] += (a * (r + l) * (r - l + 1) / 2) % MOD) %= MOD;
            (((lazy[id][0] += b - a * u) %= MOD) += MOD) %= MOD;
            (lazy[id][1] += a) %= MOD;
            return;
        }
        int m = l + r >> 1;
        push(id, l, r, m);
        update(id * 2, l, m, u, v, a, b);
        update(id * 2 + 1, m + 1, r, u, v, a, b);
        st[id] = (st[id * 2] + st[id * 2 + 1]) % MOD;
    }

    int get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return 0;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        push(id, l, r, m);
        return (get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v)) % MOD;
    }
} it;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> q;
    while (q--) {
        int type, l, r, a, b;
        cin >> type >> l >> r;
        if (type == 1) {
            cin >> a >> b;
            it.update(1, 1, n, l, r, a, b);
        }
        else cout << it.get(1, 1, n, l, r) << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/segtree_itladder