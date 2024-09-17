#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 5;

int n, c, depth[N];
vector<int> adj[N];

void DFS(int u) {
    for (vector<int>::iterator v = adj[u].begin(); v != adj[u].end(); v++) {
        depth[*v] = depth[u] + 1;
        DFS(*v);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n >> c;
    for (int i = 1; i <= c; i++) {
        int par, leftChild, rightChild;
        cin >> par >> leftChild >> rightChild;
        adj[par].push_back(leftChild);
        adj[par].push_back(rightChild);
    }
    depth[1] = 1;
    DFS(1);
    for (int i = 1; i <= n; i++) cout << depth[i] << "\n";
}

// https://oj.vnoi.info/problem/vcoldwat
