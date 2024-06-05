/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:23:55 - 05/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 3e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;
const int LOG   = __lg(N) + 1;

int n, q, high[N], par[N][LOG];
vector<int> adj[N];

void DFS(int u){
    for (int v : adj[u]){
        if (v == par[u][0]) continue;
        high[v] = high[u] + 1;
        par[v][0] = u;
        forUp(i, 1, LOG - 1, 1) par[v][i] = par[par[v][i - 1]][i - 1];
        DFS(v);
    }
}

int LCA(int u, int v){
    if (high[u] > high[v]) swap(u, v);
    int dist = high[v] - high[u];
    for (int i = 0; (1 << i) <= dist; i++){
        if (dist >> i & 1) v = par[v][i];
    }
    if (u == v) return u;
    forDown(i, LOG - 1, 0, -1){
        if (par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int dist(int u, int v){
    return high[u] + high[v] - 2 * high[LCA(u, v)];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    forUp(i, 1, n - 1, 1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    cin >> q;
    while (q--){
        int a, b, c;
        cin >> a >> b >> c;
        if (dist(a, b) <= c) cout << b << endl;
        else{
            int lca = LCA(a, b);
            int d = high[a] - high[lca];
            if (d >= c){
                for (int i = 0; (1 << i) <= c; i++){
                    if (c >> i & 1) a = par[a][i];
                }
                cout << a << endl;
            }
            else{
                c -= d;
                c = high[b] - high[lca] - c;
                for (int i = 0; (1 << i) <= c; i++){
                    if (c >> i & 1) b = par[b][i];
                }
                cout << b << endl;
            }
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

// https://oj.vnoi.info/problem/secondthread_tree_sloth