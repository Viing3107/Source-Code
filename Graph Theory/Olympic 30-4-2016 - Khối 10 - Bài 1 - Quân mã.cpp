/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:23:30 - 12/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "QUANMA"
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define endl                    "\n"

using namespace std;

const int N     = 1e3 + 3;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, m, x, y, x2, y2, visited[N][N];
int di[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dj[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void BFS(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    visited[x][y] = 0;
    while (!Q.empty()) {
        pair<int, int> top = Q.front();
        Q.pop();
        int i = top.first;
        int j = top.second;
        forUp(k, 0, 7, 1) {
            int i1 = i + di[k];
            int j1 = j + dj[k];
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && visited[i1][j1] == -1) {
                visited[i1][j1] = visited[i][j] + 1;
                Q.push({i1, j1});
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

    cin >> n >> m >> x >> y >> x2 >> y2;
    memset(visited, -1, sizeof visited);
    BFS(x, y);
    cout << visited[x2][y2];
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/olp304_16_quanma