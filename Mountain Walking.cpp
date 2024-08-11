/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:02:10 - 11/08/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define SZ(v)                   (int) v.size()
#define all(v)                  v.begin(), v.end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e2 + 2;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int BLOCK_SIZE    = sqrt(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, a[N][N], result = INF, visited[N][N];
int di[] = {-1, 0, 0, 1};
int dj[] = {0, -1, 1, 0};

bool inside(int x, int y) {return x >= 1 && x <= n && y >= 1 && y <= n;}

void DFS(int i, int j, int l, int r) {
    visited[i][j] = true;
    forUp(k, 0, 3, 1) {
        int i1 = i + di[k];
        int j1 = j + dj[k];
        if (inside(i1, j1) && !visited[i1][j1] && a[i1][j1] >= l && a[i1][j1] <= r) DFS(i1, j1, l, r);
    }
}

int f(int l, int r) {
    memset(visited, false, sizeof visited);
    if (a[1][1] >= l && a[1][1] <= r) DFS(1, 1, l, r);
    else return false;
    return visited[n][n];
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
    forUp(i, 1, n, 1) forUp(j, 1, n, 1) cin >> a[i][j];
    forUp(i, 0, 111, 1) {
        int l = 0, r = 111;
        while (r - l >= 0) {
            int m = l + r >> 1;
            if (f(i, i + m)) {
                result = min(result, m);
                r = m - 1;
            }
            else l = m + 1;
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

// https://oj.vnoi.info/problem/mtwalk