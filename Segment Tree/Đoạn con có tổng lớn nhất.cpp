/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define MASK(i)                 (1ll << (i))
#define BIT(i, n)               ((n) >> (i) & 1)
#define SZ(v)                   (int) (v).size()
#define all(v)                  (v).begin(), (v).end()
#define LOG(x)                  (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof v.begin() it = v.begin(); it != v.end(); it++)

using namespace std;

const int       N           = 5e4 + 4;
const int       MOD         = 1e9 + 7;
const int       BLOCK_SIZE  = sqrt(N) + 5;
const int       INF         = 0x3f3f3f3f;
const double    EPS         = 1e-6;

int n, q, a[N];

struct node {
    int prefix, suffix, val, sum, maxVal;

    friend node merge(const node &u, const node &v) {
        node res;
        res.prefix = max(u.prefix, u.sum + v.prefix);
        res.suffix = max(v.suffix, v.sum + u.suffix);
        res.val = max({u.val, v.val, u.suffix + v.prefix});
        res.sum = u.sum + v.sum;
        res.maxVal = max(u.maxVal, v.maxVal);
        return res;
    }
};

struct SegmentTree {
    node st[4 * N];

    void build(int id, int l, int r) {
        if (l == r) {
            st[id].prefix = st[id].suffix = st[id].val = max(0, a[l]);
            st[id].maxVal = st[id].sum = a[l];
            return;
        }
        int m = l + r >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        st[id] = merge(st[id * 2], st[id * 2 + 1]);
    }

    node get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) {
            node res;
            res.sum = 0;
            res.prefix = res.suffix = res.val = res.maxVal = -INF;
            return res;
        }
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        return merge(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
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

    cin >> n;
    forUp(i, 1, n, 1) cin >> a[i];
    it.build(1, 1, n);
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        node ans = it.get(1, 1, n, l, r);
        cout << (ans.val ? ans.val : ans.maxVal) << endl;
    }

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/gss
