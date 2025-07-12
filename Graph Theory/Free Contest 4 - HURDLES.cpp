/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)

using namespace std;

const int       N           = 3e2 + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;

int n, m, t, minCost[N][N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    memset(minCost, 0x3f, sizeof minCost);
    cin >> n >> m >> t;
    forUp (i, 1, m, 1) {
        int u, v, w;
        cin >> u >> v >> w;
        minCost[u][v] = w;
    }
    forUp (k, 1, n, 1) forUp (u, 1, n, 1) forUp (v, 1, n, 1)
        minCost[u][v] = min(minCost[u][v], max(minCost[u][k], minCost[k][v]));
    while (t--) {
        int u, v;
        cin >> u >> v;
        cout << (minCost[u][v] == INF ? -1 : minCost[u][v]) << endl;
    }
}

/*

    /\_/\
   (= ._.)
   />0   \>1 Viing3107

*/

// https://oj.vnoi.info/problem/fc004_hurdles
