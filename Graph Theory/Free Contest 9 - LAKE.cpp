/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 23:51:33 - 10/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define endl                    "\n"

using namespace std;

const int N     = 1e2 + 2;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, m, k, a[N][N], visited[N][N], result, cnt;
int di[] = {-1, 0, 0, 1};
int dj[] = {0, -1, 1, 0};

void DFS(int i, int j) {
    cnt++;
    visited[i][j] = true;
    forUp(k, 0, 3, 1) {
        int i1 = i + di[k];
        int j1 = j + dj[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] && !visited[i1][j1]) DFS(i1, j1);
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

    cin >> n >> m >> k;
    forUp(i, 1, n, 1) forUp(j, 1, m, 1) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    forUp(i, 1, n, 1) forUp(j, 1, m, 1) {
        if (a[i][j] && !visited[i][j]) {
            cnt = 0;
            DFS(i, j);
            result = max(result, cnt);
        }
    }
    cout << result;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc009_lake