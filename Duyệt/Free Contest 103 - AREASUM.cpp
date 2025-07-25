/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 11:19:01 - 25/07/2025

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

int n, m, a[N], b[N], res, preSumA[N], preSumB[N], preSumD[N], c[N], d[N];

/*
với mọi i < j và k < l

O(n^4)
res = tổng (a[j] - a[i]) * (b[l] - b[k])

O(n^3)
res = tổng (a[j] - a[i]) * ((l - 1) * b[l] - preSumB[l - 1])

O(n^2)
res = tổng ((j - 1) * a[j] - preSumA[j - 1]) * ((l - 1) * b[l] - preSumB[l - 1])

đặt 
    c[j] = (j - 1) * a[j] - preSumA[j - 1]
    d[l] = (l - 1) * b[l] - preSumB[l - 1]
res = tổng c[j] * d[l] = tổng c[j] * (preSumD[m] - preSumD[1])
*/

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
        cin >> a[i];
        preSumA[i] = preSumA[i - 1] + a[i];
    }
    forUp(i, 1, m, 1) {
        cin >> b[i];
        preSumB[i] = preSumB[i - 1] + b[i];
    }
    forUp(j, 2, n, 1) c[j] = ((j - 1) * a[j] - preSumA[j - 1]) % MOD;
    forUp(l, 2, m, 1) d[l] = ((l - 1) * b[l] - preSumB[l - 1]) % MOD;
    forUp(i, 2, m, 1) preSumD[i] = (preSumD[i - 1] + d[i]) % MOD;
    int res = 0;
    forUp(i, 2, n, 1) (res += c[i] * preSumD[m]) %= MOD;
    cout << res;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/fc103_areasum