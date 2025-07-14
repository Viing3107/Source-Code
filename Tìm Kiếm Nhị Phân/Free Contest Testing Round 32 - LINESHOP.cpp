/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh

*/

#include                        <iostream>
#include                        <algorithm>
#define endl                    "\n"
#define task                    "test"
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)

using namespace std;

const int       N           = 1e5 + 1;
const int       M           = 1e2 + 1;

int n, q, a[N], pos[N][M], preSum[N], x, p;

/*
pos[i][j] = idx: vi tri dau tien lon hon i thoa man a[idx] <= j

*/

int get(int l, int r) {return preSum[r] - preSum[l - 1];}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> q;
    forUp (i, 1, n, 1) {
        cin >> a[i];
        preSum[i] = preSum[i - 1] + a[i];
    }
    forUp (j, 0, 100, 1) pos[n][j] = n + 1;
    forDown (i, n - 1, 0, -1) {
        forUp (j, 0, 100, 1) pos[i][j] = pos[i + 1][j];
        forUp (j, a[i + 1], 100, 1) pos[i][j] = i + 1;
    }
    while (q--) {
        cin >> x >> p;
        int res = 0;
        while (p <= n && x) {
            int idx = upper_bound(preSum + p, preSum + n + 1, preSum[p - 1] + x) - preSum - 1;
            if (idx >= p) {
                res += idx - p + 1;
                x -= get(p, idx);
            }
            if (idx == n) break;
            p = pos[idx][x];
        }
        cout << res << endl;
    }
}

/*

    /\_/\
   (= ._.)
   />0   \>1 Viing3107

*/

//  https://oj.vnoi.info/problem/fct032_lineshop
