#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

const int N = 3e2 + 2;
const int INF = 0x7fffffff;

int n, w[N], a[N][N], result = INF, visited[N];
vector<pair<int, int>> adj[N];

int prim(int s) {
    memset(visited, false, sizeof visited);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    int sum = w[s];
    Q.push({0, s});
    while (!Q.empty()) {
        pair<int, int> top = Q.top();
        Q.pop();
        int u = top.second, weight = top.first;
        if (visited[u]) continue;
        sum += weight;
        if (sum >= result) return INF;
        visited[u] = true;
        for (auto &it : adj[u]) {
            int v = it.first, p = it.second;
            if (!visited[v]) Q.push({min(p, w[v]), v});
        }
    }
    return sum;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
        if (i != j) adj[i].push_back({j, a[i][j]});
    }
    for (int i = 1; i <= n; i++) result = min(result, prim(i));
    cout << result;
}

// https://oj.vnoi.info/problem/fwater