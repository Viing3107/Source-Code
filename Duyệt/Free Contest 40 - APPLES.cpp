/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 09:58:28 - 14/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 5e4 + 4;
const int M     = 20;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, m, depth[N][M], cnt[N][M];
char a[N][M];

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
    forUp(j, 1, m, 1) depth[n + 1][j] = n + 1;
    forUp(j, 1, m, 1) forDown(i, n, 1, -1) {
        if (a[i][j] == 'a') depth[i][j] = depth[i + 1][j] - 1;
        else if (a[i][j] == '.') depth[i][j] = depth[i + 1][j];
        else depth[i][j] = i;
    }
    forUp(j, 1, m, 1) forDown(i, n, 1, -1) {
        if (a[i][j] == 'a') swap(a[i][j], a[depth[i][j]][j]);
    }
    forUp(i, 1, n, 1) {
        forUp(j, 1, m, 1) cout << a[i][j];
        cout << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc040_apples