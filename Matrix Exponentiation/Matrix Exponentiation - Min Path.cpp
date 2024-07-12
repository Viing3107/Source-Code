/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:54:28 - 12/07/2024

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

const int N     = 105;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, m, k, result = INF;

struct matrix{
    int a[N][N];

    matrix() {memset(a, 0x3f, sizeof a);}

    friend matrix operator* (matrix u, matrix v) {
        matrix res;
        forUp(i, 1, 100, 1) forUp(j, 1, 100, 1) forUp(k, 1, 100, 1) res.a[i][j] = min(res.a[i][j], u.a[i][k] + v.a[k][j]);
        return res;
    }

    friend matrix operator^ (matrix a, int n) {
        matrix res;
        forUp(i, 1, 100, 1) res.a[i][i] = 0;
        for (; n; n >>= 1, a = a * a) {
            if (n & 1) res = res * a;
        }
        return res;
    }
} A, T;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m >> k;
    forUp(i, 1, m, 1) {
        int u, v, w;
        cin >> u >> v >> w;
        T.a[u][v] = w;
    }
    A = T ^ k;
    forUp(i, 1, n, 1) forUp(j, 1, n, 1) result = min(result, A.a[i][j]);
    if (result > 1e18) cout << "IMPOSSIBLE";
    else cout << result;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/errichto_matexp_minpath