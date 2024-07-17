/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:34:51 - 16/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(st, v)          for (typeof((v).begin()) st = (v).begin(); st != (v).end(); st++)

using namespace std;

const int N     = 2e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int a[N], st[N], en[N], tour[2 * N], cur, value[2 * N];
vector<int> adj[N];

void DFS(int u, int par = -1) {
    tour[++cur] = u;
    st[u] = cur;
    for (auto &v : adj[u]) if (v != par) DFS(v, u);
    tour[++cur] = u;
    en[u] = cur;
}

struct SegmentTree{
    int st[8 * N];

    void build(int id, int l, int r) {
        if (l == r) {
            st[id] = value[l];
            return;
        }
        int m = l + r >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    void update(int id, int l, int r, int idx, int val) {
        if (idx < l || idx > r) return;
        if (l == r) {
            st[id] = val;
            return;
        }
        int m = l + r >> 1;
        update(id * 2, l, m, idx, val);
        update(id * 2 + 1, m + 1, r, idx, val);
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

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    int n, q;
    cin >> n >> q;
    forUp(i, 1, n, 1) cin >> a[i];
    forUp(i, 1, n - 1, 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    forUp(i, 1, n, 1) {
        value[st[i]] = a[i];
        value[en[i]] = -a[i];
    }
    it.build(1, 1, cur);
    // forUp(i, 1, cur, 1) cout << value[i] << " ";
    while (q--) {
        int type, u, x;
        cin >> type;
        if (type == 1) {
            cin >> u >> x;
            it.update(1, 1, cur, st[u], x);
            it.update(1, 1, cur, en[u], -x);
        }
        else {
            cin >> u;
            cout << it.get(1, 1, cur, st[1], st[u]) << endl;
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

// https://oj.vnoi.info/problem/euler_b