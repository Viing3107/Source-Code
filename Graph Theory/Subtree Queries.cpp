/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 10:07:17 - 22/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 2e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, q, a[N], tour[N], st[N], en[N], numNode, type, s, x;
vector<int> adj[N];

struct SegmentTree{
    int st[4 * N];

    void build(int id, int l, int r){
        if (l == r){
            st[id] = a[tour[l]];
            return;
        }
        int m = l + r >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    void update(int id, int l, int r, int idx, int val){
        if (idx < l || idx > r) return;
        if (l == r){
            st[id] = val;
            a[tour[idx]] = val;
            return;
        }
        int m = l + r >> 1;
        update(id * 2, l, m, idx, val);
        update(id * 2 + 1, m + 1, r, idx, val);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    int get(int id, int l, int r, int u, int v){
        if (r < u || l > v) return 0;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
    }
} it;

void DFS(int u, int par){
    tour[++numNode] = u;
    st[u] = numNode;
    for (auto v : adj[u]){
        if (v == par) continue;
        DFS(v, u);
    }
    en[u] = numNode;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> q;
    forUp(i, 1, n, 1) cin >> a[i];
    forUp(i, 1, n - 1, 1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    it.build(1, 1, n);
    while (q--){
        cin >> type;
        if (type == 1){
            cin >> s >> x;
            it.update(1, 1, n, st[s], x);
        }
        else{
            cin >> s;
            cout << it.get(1, 1, n, st[s], en[s]) << "\n";
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

// https://oj.vnoi.info/problem/euler_a