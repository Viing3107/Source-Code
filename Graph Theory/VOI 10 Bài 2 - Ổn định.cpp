/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh

*/

#include                        <iostream>
#include                        <unordered_set>
#include                        <bitset>
#include                        <queue>
#define endl                    "\n"
#define task                    "test"
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)

using namespace std;

const int       N           = 1e4 + 5;

int n, m, start, visited[N];
unordered_set<int> adj[N];
bitset<N> stable;

void BFS(int s) {
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v : adj[u]) {
            if (stable[v]) continue;
            if (!visited[v]) {
                if (v != s) {
                    visited[v] = visited[u] + 1;
                    q.push(v);
                }
            }
            else {
                if (visited[v] == visited[u] + 1) {
                    stable[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m >> start;
    forUp (i, 1, m, 1) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
    }
    BFS(start);
    int res = 0;
    forUp (i, 1, n, 1) res += stable[i];
    cout << res;

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 Viing3107

*/

// https://oj.vnoi.info/problem/stable
