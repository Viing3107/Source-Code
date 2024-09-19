#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, q;

struct SegmentTree {
    struct node {
        int val, lazy[2];
    } st[4 * N];

    void push(int id, int l, int r, int m) {
        (st[id * 2].val += (m - l + 1) * st[id].lazy[0] + (l + m) * (m - l + 1) / 2 * st[id].lazy[1]) %= MOD;
        (st[id * 2].lazy[0] += st[id].lazy[0]) %= MOD;
        (st[id * 2].lazy[1] += st[id].lazy[1]) %= MOD;

        (st[id * 2 + 1].val += (r - m) * st[id].lazy[0] + (m + 1 + r) * (r - m) / 2 * st[id].lazy[1]) %= MOD;
        (st[id * 2 + 1].lazy[0] += st[id].lazy[0]) %= MOD;
        (st[id * 2 + 1].lazy[1] += st[id].lazy[1]) %= MOD;

        st[id].lazy[0] = 0;
        st[id].lazy[1] = 0;
    }

    void update(int id, int l, int r, int u, int v, int x, int y) {
        if (r < u || l > v) return;
        if (u <= l && r <= v) {
            (((st[id].val += (r - l + 1) * (y - u * x)) %= MOD) += MOD) %= MOD;
            (st[id].val += (l + r) * (r - l + 1) / 2 * x) %= MOD;
            (((st[id].lazy[0] += y - u * x) %= MOD) += MOD) %= MOD;
            (st[id].lazy[1] += x) %= MOD;
            return;
        }
        int m = l + r >> 1;
        push(id, l, r, m);
        update(id * 2, l, m, u, v, x, y);
        update(id * 2 + 1, m + 1, r, u, v, x, y);
        st[id].val = (st[id * 2].val + st[id * 2 + 1].val) % MOD;
    }

    int get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return 0;
        if (u <= l && r <= v) return st[id].val;
        int m = l + r >> 1;
        push(id, l, r, m);
        return (get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v)) % MOD;
    }
} it;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    while (q--) {
        int type, l, r, x, y;
        cin >> type >> l >> r;
        if (type == 1) {
            cin >> x >> y;
            it.update(1, 1, n, l, r, x, y);
        }
        else cout << it.get(1, 1, n, l, r) << "\n";
    }
}

// https://marisaoj.com/problem/212
