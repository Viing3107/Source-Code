/*
    Author : Do Quang Vinh
    Vietnam National University - Ha Noi
    Created : 21:18:22 - 17/11/2025

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define gcd(x, y)               __gcd(x, y)
#define MASK(i)                 (1ll << (i))
#define BIT(i, n)               ((n) >> (i) & 1)
#define SZ(v)                   (int) (v).size()
#define lcm(x, y)               x / gcd(x, y) * y
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

int n, k, pos = 1;
pair<int, int> a[N];

bool f(int x) {
    forUp (i, 1, k, 1) {
        if (a[i].first >= pos && a[i].first <= x && a[i].second >= pos && a[i].second <= x) return false;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> k;
    forUp (i, 1, k, 1) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + k + 1);
    int res = 0;
    while (pos <= n) {
        res++;
        int l = pos, r = n, cur = pos;
        while (r - l >= 0) {
            int m = l + r >> 1;
            if (f(m)) {
                cur = m;
                l = m + 1;
            }
            else r = m - 1;
        }
        pos = cur + 1;
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

// https://oj.vnoi.info/problem/fc024_photo