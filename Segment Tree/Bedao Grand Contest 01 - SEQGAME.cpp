/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 18:26:29 - 15/08/2024

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

int n, q, result = INF;

struct SegmentTree {
    int st[4 * N], lazy[4 * N];
    
    void push(int id) {
        st[id * 2] += lazy[id];
        st[id * 2 + 1] += lazy[id];
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if (r < u || l > v) return;
        if (u <= l && r <= v) {
            st[id] += val;
            lazy[id] += val;
            return;
        }
        int m = l + r >> 1;
        push(id);
        update(id * 2, l, m, u, v, val);
        update(id * 2 + 1, m + 1, r, u, v, val);
        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }

    int get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return -INF;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        push(id);
        return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
    }
} it;

struct query {
    int l, r, val;
} Q[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> q;
    forUp(i, 1, q, 1) {
        cin >> Q[i].l >> Q[i].r >> Q[i].val;
        it.update(1, 1, n, Q[i].l, Q[i].r, Q[i].val);
    }
    forUp(i, 1, q, 1) {
        it.update(1, 1, n, Q[i].l, Q[i].r, -Q[i].val);
        result = min(result, it.get(1, 1, n, 1, n));
        it.update(1, 1, n, Q[i].l, Q[i].r, Q[i].val);
    }
    cout << result;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bedao_g01_seqgame