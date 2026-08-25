/*
    Author: Do Quang Vinh
    VNU University of Engineering and Technology, Hanoi, Vietnam
    Created: 10:45:32 25/08/2026

*/

#include <bits/stdc++.h>
#define endl                   "\n"
#define task                   "GOLF"
#define int                    long long
#define double                 long double
#define gcd(x, y)              __gcd(x, y)
#define MASK(i)                (1ll << (i))
#define SZ(v)                  (int)(v).size()
#define BIT(i, n)              ((n) >> (i) & 1)
#define lcm(x, y)              x / gcd(x, y) * y
#define ALL(v)                 (v).begin(), (v).end()
#define LOG(x)                 (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)   for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step) for (int i = (l); i >= (r); i += step)

using namespace std;

const int    LEVEL      = 20;
const int    BASE       = 311;
const int    BLOCK_SIZE = 320;
const double EPS        = 1e-6;
const int    N          = 5e2 + 5;
const int    VAL        = 1e6 + 6;
const int    MOD        = 1e9 + 7;
const int    INF        = 0x3f3f3f3f3f3f3f3f;

int n, m, grid[N][N];
bool hole[N][N], visited[N][N];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
pair<int, int> startHole;

bool inside(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

bool BFS(int x) {
    queue<pair<int, int>> Q;
    Q.push(startHole);
    memset(visited, false, sizeof visited);
    visited[startHole.first][startHole.second] = true;

    while (!Q.empty()) {
        auto [i, j] = Q.front();
        Q.pop();
        forUp (k, 0, 3, 1) {
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            if (inside(i1, j1) && !visited[i1][j1] && abs(grid[i][j] - grid[i1][j1]) <= x) {
                Q.push({i1, j1});
                visited[i1][j1] = true;
            }
        }
    }

    forUp (i, 1, n, 1) forUp (j, 1, m, 1) if (hole[i][j] && !visited[i][j]) return false;
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> m;
    forUp (i, 1, n, 1) forUp (j, 1, m, 1) cin >> grid[i][j];
    forUp (i, 1, n, 1) forUp (j, 1, m, 1) {
        cin >> hole[i][j];
        if (hole[i][j]) startHole = {i, j};
    }

    // forUp (i, 1, n, 1) forUp (j, 1, m, 1) cout << grid[i][j] << " \n"[j == m];
    // forUp (i, 1, n, 1) forUp (j, 1, m, 1) cout << hole[i][j] << " \n"[j == m];
    int left = 0, right = 1e9, res = 1e9;
    while (right - left >= 0) {
        int mid = left + right >> 1;
        if (BFS(mid)) {
            res = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << res;

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    />0   \>1
*/

// https://oj.vnoi.info/problem/olp304_18_golf