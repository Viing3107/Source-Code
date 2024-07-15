/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 08:19:44 - 15/07/2024

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

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, k, a[N], dp[N];

struct SegmentTree{
    int st[4 * N];

    SegmentTree() {memset(st, -0x3f, sizeof st);}

    void update(int id, int l, int r, int idx, int val) {
        if (idx < l || idx > r) return;
        if (l == r) {
            st[id] = max(st[id], val);
            return;
        }
        int m = l + r >> 1;
        update(id * 2, l, m, idx, val);
        update(id * 2 + 1, m + 1, r, idx, val);
        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }

    int get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return -INF;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
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

    cin >> n >> k;
    forUp(i, 1, n, 1) cin >> a[i];
    forUp(i, 1, n, 1) {
        dp[i] = max(0ll, it.get(1, 1, n, max(1ll, i - k), i - 1)) + a[i];
        it.update(1, 1, n, i, dp[i]);
    }
    cout << max(0ll, *max_element(dp + 1, dp + n + 1));
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/segtree_itmed