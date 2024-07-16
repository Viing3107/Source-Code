/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 01:55:36 - 17/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 2e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, q;

struct SegmentTree{
    int st[4 * N], lazy[4 * N], lazySet[4 * N];

    void push(int id, int l, int r, int m) {
        if (lazySet[id]) {
            st[id * 2] = 0;
            st[id * 2 + 1] = 0;
            lazySet[id * 2] = lazySet[id];
            lazySet[id * 2 + 1] = lazySet[id];
            lazy[id * 2] = 0;
            lazy[id * 2 + 1] = 0;
            lazySet[id] = 0;
        }

        if (lazy[id]) {
            if ((m - l + 1) % 2) st[id * 2] ^= lazy[id];
            if ((r - m) % 2) st[id * 2 + 1] ^= lazy[id];
            lazy[id * 2] ^= lazy[id];
            lazy[id * 2 + 1] ^= lazy[id];
            lazy[id] = 0;    
        }
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if (r < u || l > v) return;
        if (u <= l && r <= v) {
            if ((r - l + 1) % 2) st[id] ^= val;
            lazy[id] ^= val;
            return;
        }
        int m = l + r >> 1;
        push(id, l, r, m);
        update(id * 2, l, m, u, v, val);
        update(id * 2 + 1, m + 1, r, u, v, val);
        st[id] = st[id * 2] ^ st[id * 2 + 1];
    }

    void set(int id, int l, int r) {
        st[id] = 0;
        lazy[id] = 0;
        lazySet[id] = 1;
    }

    int get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return 0;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        push(id, l, r, m);
        return get(id * 2, l, m, u, v) ^ get(id * 2 + 1, m + 1, r, u, v);
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
        int type, l, r, x;
        cin >> type >> l >> r;
        if (type == 1) {
            cin >> x;
            it.update(1, 1, n, l, r, x);
        }
        else {
            cout << it.get(1, 1, n, l, r) << endl;
            it.set(1, 1, n);
        }
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bedao_m20_b

// code được lấy ý tưởng từ : https://www.facebook.com/share/p/F5fkia96Ar1xhHQR/
// ảnh ví dụ : https://www.facebook.com/photo.php?fbid=487673287144451&set=p.487673287144451&type=3