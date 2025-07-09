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

const int       N           = 1e3 + 5;
const int       BASE        = 31;
const int       MOD         = 1e9 + 7;
const int       BLOCK_SIZE  = sqrt(N) + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, m;
char a[N][N];
int dx[] = {0, 1, 1, 1};
int dy[] = {1, -1, 0, 1};

bool inside(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int cnt(int i, int j) {
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int res = 0;
    forUp (k, 0, 8, 1) if (a[i][j] == '#') {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        res += inside(i1, j1) && a[i1][j1] == '#';
    }
    return res;
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
    forUp (i, 1, n, 1) forUp (j, 1, m, 1) cin >> a[i][j];
    int res = 0;
    forUp (i, 1, n, 1) forUp (j, 1, m, 1) if (a[i][j] == '#') {
        forUp (k, 0, 3, 1) {
            int i1 = i + dx[k];
            int j1 = j + dy[k];
          res += inside(i1, j1) && a[i1][j1] == '#';
        }
    }
    int add = 0;
    forUp (i, 1, n, 1) forUp (j, 1, m, 1) if (a[i][j] == '.') {
        a[i][j] = '#';
        add = max(add, cnt(i, j));
        a[i][j] = '.';
    }
    cout << res + add;


    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 Viing3107

*/

// https://oj.vnoi.info/problem/fcb032_fnhouses
