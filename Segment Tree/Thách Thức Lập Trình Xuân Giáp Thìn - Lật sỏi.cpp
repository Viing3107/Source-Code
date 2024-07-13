/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 11:01:14 - 13/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define endl                    "\n"

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, q, type, l, r;

struct SegmentTree{
    int st[4 * N], lazy[4 * N];

    void push(int id, int l, int r, int m) {
        if (lazy[id]) {
            st[id * 2] = m - l + 1 - st[id * 2];
            st[id * 2 + 1] = r - m - st[id * 2 + 1];
            (lazy[id * 2] += 1) %= 2;
            (lazy[id * 2 + 1] += 1) %= 2;
            lazy[id] = 0;
        }
    }

    void update(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return;
        if (u <= l && r <= v) {
            st[id] = r - l + 1 - st[id];
            (lazy[id] += 1) %= 2;
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
        cin >> type >> l >> r;
        l++;
        r++;
        if (type) cout << it.get(1, 1, n, l, r) << endl;
        else it.update(1, 1, n, l, r);
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/dovui_2024_b