/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 23:30:51 - 07/10/2024

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
#define forEach(it, v)          for (typeof v.begin() it = v.begin(), _e = it.end(); it != _e; it++)

using namespace std;

const int       N           = 1e3 + 3;
const int       MOD         = 1e9 + 7;
const int       LOG         = __lg(N) + 5;
const int       BLOCK_SIZE  = sqrt(N) + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-7;

/*
    chặt nhị phân
        2 vòng for trâu
        DFS

*/

struct point {
    int x, y;

    friend istream &operator >> (istream &stream, point &p) {
        stream >> p.x >> p.y;
        return stream;
    }

    friend bool operator < (const point &u, const point &v) {
        return u.x == v.x ? u.y < v.y : u.x < v.x;
    }

    friend double dist(const point &u, const point &v) {
        return sqrt(pow(u.x - v.x, 2) + pow(u.y - v.y, 2));
    }
} a[N];

int n;
vector<int> adj[N];
bool visited[N];

void DFS(int u) {
    visited[u] = true;
    for (auto &v : adj[u]) if (!visited[v]) DFS(v);
}

bool f(double x) {
    memset(visited, false, sizeof visited);
    forUp(i, 1, n, 1) adj[i].clear();
    forUp(i, 1, n - 1, 1) forUp(j, i + 1, n, 1) {
        if (dist(a[i], a[j]) + EPS <= 2 * x) {
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
    DFS(1);
    forUp(i, 1, n, 1) if (!visited[i]) return false;
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

    cin >> n;
    forUp(i, 1, n, 1) cin >> a[i];
    sort(a + 1, a + n + 1);
    double l = 0, r = 1e9;
    while (r - l > EPS) {
        double m = (l + r) / 2;
        if (f(m)) r = m;
        else l = m;
    }
    cout << fixed << setprecision(9) << r;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/coci2021_r2_odasiljaci