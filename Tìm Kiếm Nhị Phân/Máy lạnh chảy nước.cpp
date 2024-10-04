/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 19:38:28 - 04/10/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define SZ(v)                   (int) v.size()
#define all(v)                  v.begin(), v.end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)

using namespace std;

const int N             = 1e2 + 2;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int t, n, a, b, x[N];

string solve() {
    int idx;
    idx = upper_bound(x + 1, x + n + 1, x[1] + a) - x;
    if (idx > n || x[n] - x[idx] <= b) return "YES\n";
    idx = upper_bound(x + 1, x + n + 1, x[1] + b) - x;
    if (idx > n || x[n] - x[idx] <= a) return "YES\n";
    return "NO\n";
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
        cin >> n >> a >> b;
        forUp(i, 1, n, 1) cin >> x[i];
        cout << solve();
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/vnoicup23_r3_a