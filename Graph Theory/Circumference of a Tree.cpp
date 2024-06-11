/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:36:26 - 11/06/2024

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

int n, high[N];
vector<int> adj[N];

void DFS(int u, int par){
    for (auto v : adj[u]){
        if (v == par) continue;
        high[v] = high[u] + 1;
        DFS(v, u);
    }
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
    DFS(1, 0);
    int node, maxHigh = -1;
    forUp(i, 1, n, 1){
        if (high[i] > maxHigh){
            maxHigh = high[i];
            node = i;
        }
    }
    memset(high, 0, sizeof high);
    DFS(node, 0);
    cout << *max_element(high + 1, high + n + 1) * 3;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/secondthread_tree_circumference