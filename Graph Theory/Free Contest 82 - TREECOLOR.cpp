/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:34:40 - 09/06/2024

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

int n, u, v, color[N], result[N];
vector<int> adj[N];
set<int> cnt[N];

void DFS(int u, int par = 0){
    cnt[u].insert(color[u]);
    for (auto v : adj[u]){
        if (v == par) continue;
        DFS(v, u);
        if (cnt[u].size() < cnt[v].size()) swap(cnt[u], cnt[v]);
        for (auto it : cnt[v]) cnt[u].insert(it);
    }
    result[u] = cnt[u].size();
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
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    forUp(i, 1, n, 1) cin >> color[i];
    DFS(1);
    forUp(i, 1, n, 1) cout << result[i] << endl;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc082_treecolor
