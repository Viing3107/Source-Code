/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define BIT(i, n)               ((n) >> (i) & 1)
#define SZ(v)                   (int) (v).size()
#define ALL(v)                  (v).begin(), (v).end()
#define LOG(x)                  (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof v.begin() it = v.begin(); it != v.end(); it++)

using namespace std;

const int       N           = 1e3 + 3;
const int       BASE        = 31;
const int       MOD         = 1e9 + 7;
const int       BLOCK_SIZE  = sqrt(N) + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, m, q, res[N][N], visited[N][N];
char a[N][N];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

struct point {
    int x, y;

    point() {
        x = 0;
        y = 0;
    }

    point(int x, int y) : x(x), y(y) {}

    friend bool operator == (point &u, point &v) {
        return (u.x == v.x) && (u.y == v.y);
    }

    friend bool operator != (point &u, point &v) {
        if (u.x == v.x) return u.y != v.y;
        return true;
    }

    friend bool operator < (point &u, point &v) {
        if (u.x == v.x) return u.y < v.y;
        return u.x < v.x;
    }

    friend istream& operator >> (istream &stream, point &u) {
        stream >> u.x >> u.y;
        return stream;
    }

    friend ostream& operator << (ostream &stream, point u) {
        stream << u.x << " " << u.y;
        return stream;
    }
};

struct DisjointSetUnion {
    point par[N][N];
    int sz[N][N];

    DisjointSetUnion() {
        forUp (i, 1, N - 1, 1) forUp (j, 1, N - 1, 1) {
            par[i][j] = {i, j};
            sz[i][j] = 1;
        }
    }

    point find(point u) {
        if (u == par[u.x][u.y]) return u;
        return par[u.x][u.y] = find(par[u.x][u.y]);
    }

    void joint(point u, point v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u.x][u.y] < sz[v.x][v.y]) swap(u, v);
        par[v.x][v.y] = u;
        sz[u.x][u.y] += sz[v.x][v.y];
    }
} dsu;

namespace subtask1 {
    void DFS(point u, point par) {
        visited[u.x][u.y] = 1;
        dsu.joint(par, u);
        forUp (i, 0, 3, 1) {
            point v(u.x + dx[i], u.y + dy[i]);
            if (!visited[v.x][v.y]) {
                if (a[v.x][v.y] == '.') DFS(v, par);
                else res[par.x][par.y]++;
            }
        }
    }

    void process() {
        forUp (i, 1, n, 1) forUp (j, 1, m, 1) {
            point u(i, j);
            if (a[i][j] == '.' && !visited[i][j]) DFS(u, u);
        }
    }
}

namespace subtask2 {
    void BFS(point par) {
        queue<point> Q;
        Q.push(par);
        visited[par.x][par.y] = 1;
        while (!Q.empty()) {
            point u = Q.front();
            Q.pop();
            dsu.joint(par, u);
            forUp(i, 0, 3, 1) {
                point v(u.x + dx[i], u.y + dy[i]);
                if (!visited[v.x][v.y]) {
                    if (a[v.x][v.y] == '.') {
                        Q.push(v);
                        visited[v.x][v.y] = 1;
                    }
                    else res[par.x][par.y]++;
                }
            }
        }
    }

    void process() {
        forUp (i, 1, n, 1) forUp (j, 1, m, 1) {
            point u(i, j);
            if (a[i][j] == '.' && !visited[i][j]) BFS(u);
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

    cin >> n >> m >> q;
    forUp (i, 1, n, 1) forUp (j, 1, m, 1) cin >> a[i][j];
    if (n <= 100 && m <= 100) subtask1::process();
    else subtask2::process();

    forUp (i, 1, q, 1) {
        point u;
        cin >> u;
        u = dsu.find(u);
        cout << res[u.x][u.y] << endl;
    }

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 Viing3107

*/

//
