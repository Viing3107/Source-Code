/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 10:04:03 - 20/07/2024

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

const int N             = 20;
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, mask[N], h[N], w[N][N], result = INF;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    forUp(i, 1, n, 1) cin >> h[i];
    forUp(i, 1, n - 1, 1) forUp(j, i + 1, n, 1) cin >> w[i][j];
    for (int i = 0; i < (1ll << n); i++) {
        int tmp = 0;
        forUp(j, 0, n - 1, 1) {
            mask[j + 1] = i >> j & 1;
            if (!mask[j + 1]) mask[j + 1]--;
            tmp += mask[j + 1] * h[j + 1];
        }
        forUp(i, 1, n - 1, 1) forUp(j, i + 1, n, 1) tmp += mask[i] * mask[j] * w[i][j];
        result = min(result, tmp);
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

// https://oj.vnoi.info/problem/backtrack_k