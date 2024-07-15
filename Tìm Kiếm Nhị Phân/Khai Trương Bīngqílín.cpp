/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 08:41:38 - 15/07/2024

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

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f;

int t, n, k, a[N];

int f(int x) {
    return n - (lower_bound(a + 1, a + n + 1, x) - a) + 1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> t;
    while (t--) {
        cin >> n >> k;
        forUp(i, 1, n, 1) cin >> a[i];
        sort(a + 1, a + n + 1);
        int l = 1, r = INF, result = -1;
        while (r - l >= 0) {
            int m = l + r >> 1;
            int tmp = f(m);
            if (tmp <= k) {
                r = m - 1;
                if (tmp > 0) result = m;
            }
            else l = m + 1; 
        }
        cout << result << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/hello23_a