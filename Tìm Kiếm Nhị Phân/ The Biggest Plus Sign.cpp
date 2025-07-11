#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)

using namespace std;

const int       N           = 5e3 + 5;

int n, m, x, y, sz = -1, preRow[N][N], preCol[N][N];
bitset<N> a[N];

int get(int x1, int y1, int x2, int y2) {
    if (x1 == x2) return preRow[x2][y2] - preRow[x1][y1 - 1];
    return preCol[x2][y2] - preCol[x1 - 1][y1];
}

bool inside(int x, int y) {return x >= 1 && x <= n && y >= 1 && y <= m;}

bool f(int i, int j, int x) {
    int i1, j1;
    i1 = i, j1 = j - x;
    if (!inside(i1, j1) || get(i1, j1, i, j) != x + 1) return false;
    i1 = i, j1 = j + x;
    if (!inside(i1, j1) || get(i, j, i1, j1) != x + 1) return false;
    i1 = i - x, j1 = j;
    if (!inside(i1, j1) || get(i1, j1, i, j) != x + 1) return false;
    i1 = i + x, j1 = j;
    if (!inside(i1, j1) || get(i, j, i1, j1) != x + 1) return false;
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m;
    forUp (i, 1, n, 1) forUp (j, 1, m, 1) {
        char c;
        cin >> c;
        a[i][j] = c - '0';
    }
    forUp (i, 1, n, 1) forUp (j, 1, m, 1) preRow[i][j] = preRow[i][j - 1] + a[i][j];
    forUp (j, 1, m, 1) forUp (i, 1, n, 1) preCol[i][j] = preCol[i - 1][j] + a[i][j];
    forUp (i, 1, n, 1) forUp (j, 1, m, 1) if (a[i][j]) {
        int l = 0, r = max(n, m);
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (f(i, j, mid)) l = mid;
            else r = mid;
        }
        if (sz < 4 * l + 1) {
            sz = 4 * l + 1;
            x = i;
            y = j;
        }
    }
    cout << sz << endl;
    if (sz != -1) cout << x << " " << y;
}

// https://oj.vnoi.info/problem/icpc21_mn_j
