/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh

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
#define forEach(it, v)          for (typeof v.begin() it = v.begin(); it != v.end(); it++)

using namespace std;

const int       N           = 1e5 + 5;
const int       BASE        = 31;
const int       MOD         = 1e9 + 7;
const int       BLOCK_SIZE  = sqrt(N) + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, q, res[N], a[N], query[N];
string s;

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
        cin >> s;
        forUp (j, 0, SZ(s) - 1, 1) a[i] |= MASK(s[j] - 'a');
    }
    forUp (i, 1, q, 1) {
        char c;
        cin >> c;
        query[i] = query[i - 1] | MASK(c - 'a');
    }
    forUp (i, 1, n, 1) {
        int l = 1, r = q, idx = 0;
        while (r - l >= 0) {
            int m = l + r >> 1;
            if (__builtin_popcount(a[i]) + __builtin_popcount(query[m]) == __builtin_popcount(a[i] | query[m])) {
                idx = m;
                l = m + 1;
            }
            else r = m - 1;
        }
        res[0]++;
        res[idx + 1]--;
    }
    forUp (i, 1, q, 1) res[i] += res[i - 1];
    forUp (i, 1, q, 1) cout << res[i] << endl;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 Viing3107

*/

// https://oj.vnoi.info/problem/fcb016_filedel
