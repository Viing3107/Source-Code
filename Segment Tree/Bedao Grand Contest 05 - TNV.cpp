/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 13:46:38 - 26/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define MASK(i)                 (1ll << (i))
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e6 + 6;
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, q, a[N];

struct SegmentTree{
    int st[4 * N], lazy[4 * N];

    void push(int id) {
        st[id * 2] = max(st[id * 2], lazy[id]);
        st[id * 2 + 1] = max(st[id * 2 + 1], lazy[id]);
        lazy[id * 2] = max(lazy[id * 2], lazy[id]);
        lazy[id * 2 + 1] = max(lazy[id * 2 + 1], lazy[id]);
        lazy[id] = 0;
    }

    void build(int id, int l, int r) {
        if (l == r) {
            st[id] = a[l];
            return;
        }
        int m = l + r >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        st[id] = max(st[id] * 2, st[id * 2 + 1]);
    }

    void point(int id, int l, int r, int idx, int val) {
        if (idx < l || idx > r) return;
        if (l == r) {
            st[id] = val;
            return;
        }
        push(id);
        int m = l + r >> 1;
        point(id * 2, l, m, idx, val);
        point(id * 2 + 1, m + 1, r, idx, val);
        st[id] = max(st[id] * 2, st[id * 2 + 1]);
    }

    void range(int val) {
        st[1] = max(st[1], val);
        lazy[1] = max(lazy[1], val);
    }

    int get(int id, int l, int r, int idx) {
        if (idx < l || idx > r) return -INF;
        if (l == r) return st[id];
        push(id);
        int m = l + r >> 1;
        return max(get(id * 2, l, m, idx), get(id * 2 + 1, m + 1, r, idx));
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
    forUp(i, 1, n, 1) cin >> a[i];
    it.build(1, 1, n);
    while (q--) {
        int type, idx, val;
        cin >> type;
        if (type == 1) {
            cin >> idx >> val;
            it.point(1, 1, n, idx, val);
        }
        else {
            cin >> val;
            it.range(val);
        }
    }
    forUp(i, 1, n, 1) cout << it.get(1, 1, n, i) << " ";
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bedao_g05_tnv