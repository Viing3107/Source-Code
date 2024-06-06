/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 19:38:41 - 06/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;
const int LOG   = __lg(N) + 1;

int n, q, par[N][LOG], high[N], val[N][LOG], d[N];
vector<pair<int, int>> adj[N];

void DFS(int u){
    for (auto it : adj[u]){
        int v = it.first;
        int w = it.second;
        if (v == par[u][0]) continue;
        high[v] = high[u] + 1;
        par[v][0] = u;
        val[v][0] = w;
        forUp(i, 1, LOG - 1, 1){
            par[v][i] = par[par[v][i - 1]][i - 1];
            val[v][i] = val[v][i - 1] + val[par[v][i - 1]][i - 1];
        }
        DFS(v);
    }
}

int LCA(int u, int v){
    if (high[u] > high[v]) swap(u, v);
    forDown(i, LOG - 1, 0, -1){
        if (high[u] <= high[par[v][i]]) v = par[v][i];
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
    return d[u] + d[v] - 2 * d[LCA(u, v)];

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
    forUp(i, 1, n - 1, 1){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    high[0] = -1;
    DFS(1);
    forUp(i, 1, n, 1){
        int u = i;
        forDown(j, LOG - 1, 0, -1){
            if (high[par[u][j]] >= 0){
                d[i] += val[u][j];
                u = par[u][j];
            }
        }
    }
    while (q--){
        int u, v;
        cin >> u >> v;
        cout << dist(u, v) << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/pwalk