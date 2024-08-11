/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:14:08 - 11/08/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define SZ(v)                   (int) v.size()
#define all(v)                  v.begin(), v.end()
#define val(x)                  (x) * ((x) + 1) / 2
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 2e5 + 5;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int BLOCK_SIZE    = sqrt(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, a[N], q;

struct SegmentTree {
    int st[4 * N];
    pair<int, int> lazy[4 * N];

    void push(int id, int l, int r, int m) {
        st[id * 2] += (m - l + 1) * lazy[id].first + val(m - l + 1) * lazy[id].second;
        st[id * 2 + 1] += (r - m) * lazy[id].first + (val(r - m) + (r - m) * (m - l + 1)) * lazy[id].second;
        lazy[id * 2].first += lazy[id].first;
        lazy[id * 2].second += lazy[id].second;
        lazy[id * 2 + 1].first += lazy[id].first + (m - l + 1) * lazy[id].second;
        lazy[id * 2 + 1].second += lazy[id].second;
        lazy[id] = {0, 0};
    }

    void build(int id, int l, int r) {
        if (l == r) {
            st[id] = a[l];
            return;
        }
        int m = l + r >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    void update(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return;
        if (u <= l && r <= v) {
            st[id] += val(r - l + 1) + (l - u) * (r - l + 1);
            lazy[id].first += l - u;
            lazy[id].second++;
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


    cin >> n;
    forUp(i, 1, n, 1) cin >> a[i];
    it.build(1, 1, n);
    cin >> q;
    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) it.update(1, 1, n, l, r);
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

// https://oj.vnoi.info/problem/fct005_query