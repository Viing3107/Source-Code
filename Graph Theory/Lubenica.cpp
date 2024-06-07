/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 23:47:49 - 07/06/2024

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
const int LOG   = __lg(N);

int n, q, u, v, w, par[N][LOG + 1], maxVal[N][LOG + 1], minVal[N][LOG + 1], high[N];
vector<pair<int, int>> adj[N];

void DFS(int u){
    for (auto it : adj[u]){
        int v = it.first;
        int w = it.second;
        if (v == par[u][0]) continue;
        high[v] = high[u] + 1;
        par[v][0] = u;
        minVal[v][0] = w;
        maxVal[v][0] = w;
        forUp(i, 1, LOG, 1){
            par[v][i] = par[par[v][i - 1]][i - 1];
            minVal[v][i] = min(minVal[v][i - 1], minVal[par[v][i - 1]][i - 1]);
            maxVal[v][i] = max(maxVal[v][i - 1], maxVal[par[v][i - 1]][i - 1]);
        }
        DFS(v);
    }
}

void solve(int u, int v){
    if (high[u] > high[v]) swap(u, v);
    int d = high[v] - high[u], resMin = INF, resMax = -INF;
    for (int i = 0; (1 << i) <= d; i++){
        if (d >> i & 1){
            resMax = max(resMax, maxVal[v][i]);
            resMin = min(resMin, minVal[v][i]);
            v = par[v][i];
        }
    }
    if (u == v){
        cout << resMin << " " << resMax << endl;
        return;
    }
    forDown(i, LOG, 0, -1){
        if (par[v][i] != par[u][i]){
            resMax = max({resMax, maxVal[u][i], maxVal[v][i]});
            resMin = min({resMin, minVal[u][i], minVal[v][i]});
            u = par[u][i];
            v = par[v][i];
        }
    }
    resMin = min({resMin, minVal[u][0], minVal[v][0]});
    resMax = max({resMax, maxVal[u][0], maxVal[v][0]});
    cout << resMin << " " << resMax << endl;
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
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    DFS(1);
    cin >> q;
    while (q--){
        cin >> u >> v;
        solve(u, v);
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/lubenica