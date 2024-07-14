/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:46:00 - 14/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, color[N], answer[N], mx[N];
vector<int> adj[N];
map<int, int> s[N];

void DFS(int u, int par = -1) {
    answer[u] = color[u];
    s[u][color[u]]++;
    mx[u] = 1;
    for (auto &v : adj[u]) {
        if (v == par) continue;
        DFS(v, u);
        if (s[u].size() < s[v].size()) {
            swap(s[u], s[v]);
            mx[u] = mx[v];
            answer[u] = answer[v];
        }
        for (auto &x : s[v]) {
            s[u][x.first] += x.second;
            int val = s[u][x.first];
            if (val > mx[u]) {
                mx[u] = val;
                answer[u] = x.first;
            }
            else if (val == mx[u]) answer[u] += x.first;
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

    cin >> n;
    forUp(i, 1, n, 1) cin >> color[i];
    forUp(i, 1, n - 1, 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    forUp(i, 1, n, 1) cout << answer[i] << " ";
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/cf_edu2e