/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 13:26:40 - 10/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for(int i = (l); i >= (r); i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define endl                    "\n"

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, m, L[N], R[N], a[N], result = -1, tmp[N];

/*
    L[i] : cột cao nhất bên trái i
    R[i] : cột cao nhất bên phải i

*/

int f(int x) {
    forUp (i, 1, n, 1) tmp[i] = max(a[i], x);
    memset(L, -0x3f, sizeof L);
    memset(R, -0x3f, sizeof R);
    forUp (i, 2, n, 1) L[i] = max(L[i - 1], tmp[i - 1]);
    forDown(i, n - 1, 1, -1) R[i] = max(R[i + 1], tmp[i + 1]);
    int res = 0;
    forUp (i, 2, n - 1, 1) res += max(0ll, min(L[i], R[i]) - tmp[i]);
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
    forUp (i, 1, n, 1) cin >> a[i];

    int l = 0, r = INF;
    while (r - l >= 0) {
        int mid = l + r >> 1;
        if (f(mid) >= m) {
            result = mid;
            l = mid + 1;
        }
        else r = mid - 1;
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

// https://oj.vnoi.info/problem/olp_kc20_buildcol