#include <bits/stdc++.h>
#define int long long
#define double long double

using namespace std;

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n, q, a[N];

struct SegmentTree {
    int st[4 * N];

    void build(int id, int l, int r) {
        if (l == r) return void(st[id] = a[l]);
        int m = l + r >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
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

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = max(0ll, a[i]);
    }
    it.build(1, 1, n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << it.get(1, 1, n, l, r) << "\n";
    }
}

// https://oj.vnoi.info/problem/fc113_idp0105a
