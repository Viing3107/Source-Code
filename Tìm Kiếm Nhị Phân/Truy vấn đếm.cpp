/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 08:44:08 - 03/10/2025

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
const int       N           = 1e5 + 5;
const int       VAL         = 1e6 + 6;
const int       MOD         = 1e9 + 7;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, q, a[N];
vector<int> pos[N];

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
        pos[a[i]].push_back(i);
    }
    // forUp (i, 1, n, 1) {
    //     for (auto &p: pos[i]) cout << p << " ";
    //     cout << endl;
    // }
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        l = lower_bound(ALL(pos[x]), l) - pos[x].begin();
        r = upper_bound(ALL(pos[x]), r) - pos[x].begin() - 1;
        cout << r - l + 1 << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://marisaoj.com/problem/79