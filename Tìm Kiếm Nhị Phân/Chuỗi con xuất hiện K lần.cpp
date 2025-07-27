/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:07:22 - 27/07/2025

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
const int       N           = 5e4 + 4;
const int       VAL         = 1e6 + 6;
const int       MOD         = 1e9 + 7;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, k, hashS[N], p[N], res;
string s;

int getHash(int l, int r) {
    return ((hashS[r] - hashS[l - 1] * p[r - l + 1]) % MOD + MOD) % MOD;
}

bool f(int m) {
    unordered_map<int, int> mp;
    forUp(i, 1, n - m + 1, 1) mp[getHash(i, i + m - 1)]++;
    for (auto &x : mp) if (x.second >= k) return true;
    return false;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> k >> s;
    s = " " + s;
    p[0] = 1;
    forUp(i, 1, n, 1) {
        hashS[i] = (hashS[i - 1] * BASE + (int) s[i]) % MOD;
        p[i] = (p[i - 1] * BASE) % MOD;
    }
    int l = 1, r = n;
    while (r - l >= 0) {
        int m = l + r >> 1;
        if (f(m)) {
            res = m;
            l = m + 1;
        }
        else r = m - 1;
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

// https://oj.vnoi.info/problem/dtksub