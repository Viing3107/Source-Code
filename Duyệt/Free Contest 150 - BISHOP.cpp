/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:47:34 - 27/07/2025

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
#define forEach(it, v)          for (typeof (v).begin() it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int       BASE        = 311;
const int       BLOCK_SIZE  = 320;
const int       N           = 1e3 + 5;
const int       VAL         = 1e6 + 6;
const int       MOD         = 1e9 + 7;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, m, a[N][N], s[2][2 * N];
int dx[] = {-1, -1};
int dy[] = {1, -1};

bool inside(int x, int y) {return x >= 1 && x <= n && y >= 1 && y <= m;}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m;
    forUp(i, 1, n, 1) forUp(j, 1, m, 1) cin >> a[i][j];
    forUp(i, 1, n + m - 1, 1) {
        int x = -1, y = -1;
        if (i <= n) x = i, y = 1;
        else x = n, y = i - n + 1;
        while (inside(x, y)) {
            s[0][i] += a[x][y];
            x += dx[0];
            y += dy[0];
        }
    }
    forUp(i, 1, n + m - 1, 1) {
        int x = -1, y = -1;
        if (i <= n) x = i, y = m;
        else x = n, y = m + n - i;
        while (inside(x, y)) {
            s[1][i] += a[x][y];
            x += dx[1];
            y += dy[1];
        }
    }
    int res = 0;
    forUp(i, 1, n, 1) forUp(j, 1, m, 1) {
        // cout << s[0][i + j - 1] + s[1][i + m - j] - a[i][j] << " \n"[j == m];
        res = max(res, s[0][i + j - 1] + s[1][i + m - j] - a[i][j]);
    }
    cout << res;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/fc150_bishop