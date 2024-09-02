#include <iostream>
#include <bitset>

using namespace std;

const int N = 1e5 + 5;

int n, q, p[22];

struct SegmentTree {
    int st[4 * N];
    bitset<4 * N> lazy;

    void push(int id, int l, int r, int m) {
        if (lazy[id]) {
            st[id * 2] = m - l + 1 - st[id * 2];
            st[id * 2 + 1] = r - m - st[id * 2 + 1];
            lazy.flip(id * 2);
            lazy.flip(id * 2 + 1);
            lazy.reset(id);
        }
    }

    void update(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return;
        if (u <= l && r <= v) {
            st[id] = r - l + 1 - st[id];
            lazy.flip(id);
            return;
        }
        int m = l + r >> 1;
        push(id, l, r, m);
        update(id * 2, l, m, u, v);
        update(id * 2 + 1, m + 1, r, u, v);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    int get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return 0;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        push(id, l, r, m);
        return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
    }
} it[22];

/*

mỗi cây quản lí 1 bit

*/

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        for (int j = 0; j <= 20; j++) {
            if (val >> j & 1) it[j].update(1, 1, n, i, i);
        }
    }
    p[0] = 1;
    for (int i = 1; i <= 21; i++) p[i] = p[i - 1] * 2;
    cin >> q;
    while (q--) {
        int type, l, r, val;
        cin >> type;
        if (type == 1) {
            cin >> l >> r;
            long long carry = 0, result = 0;
            for (int i = 0; i <= 20; i++) {
                val = it[i].get(1, 1, n, l, r) + carry;
                carry = val >> 1;
                result += (val & 1) * p[i];
            }
            cout << result + carry * p[21] << "\n";
        }
        else {
            cin >> l >> r >> val;
            for (int i = 0; i <= 20; i++) if (val >> i & 1) it[i].update(1, 1, n, l, r);
        }
    }
    
    cerr << "Run Finished";
}

// https://oj.vnoi.info/problem/fcb048_xorq