/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 14:17:02 - 14/07/2024

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

const int N     = 1e3 + 3;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, m, a[N][N], s[N][2], result, last, present;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m;
    forUp(i, 1, n, 1) {
        forUp(j, 1, m, 1) {
            cin >> a[i][j];
            if (a[i][j] > 0) s[i][1] += abs(a[i][j]);
            else s[i][0] += abs(a[i][j]);
        }
        int tmp = max(s[i][0], s[i][1]);
        if (tmp >= present) {
            last = present;
            present = tmp;
        }
        else last = max(last, tmp);
    }
    cout << last + present;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb033_gold