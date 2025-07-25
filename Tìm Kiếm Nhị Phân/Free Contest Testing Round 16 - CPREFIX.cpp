/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 20:11:10 - 25/07/2025

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
const double    EPS         = 1e-6;
const int       N           = 1e5 + 5;
const int       VAL         = 1e6 + 6;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const int       MOD[]       = {1000003, 1000000007};

string s, t;
int n, hashS[2][N], p[2][N], res[N];

int getHash(int l, int r, int k) {
    return ((hashS[k][r] -hashS[k][l - 1] * p[k][r - l + 1]) % MOD[k] + MOD[k]) % MOD[k];
}

int cnt(int length) {
    int res = 0;
    forUp(i, 2, n - length + 1, 1) 
        res += hashS[0][length] == getHash(i, i + length - 1, 0) && hashS[1][length] == getHash(i, i + length - 1, 1);
    return res + 1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> s;
    n = SZ(s);
    s = " " + s;
    p[0][0] = p[1][0] = 1;
    forUp(i, 0, 1, 1) forUp(j, 1, n, 1) {
        hashS[i][j] = (hashS[i][j - 1] * BASE + (int) s[j]) % MOD[i];
        p[i][j] = (p[i][j - 1] * BASE) % MOD[i];
    }
    res[1] = cnt(1);
    int i = 1;
    while (i < n) {
        int l = i + 1, r = n, m;
        while (r - l >= 0) {
            m = l + r >> 1;
            if (!res[m]) res[m] = cnt(m);
            if (res[m] < res[i]) r = m - 1;
            else l = m + 1;
        }
        i = m;
    }
    forUp(i, 1, n, 1){
        if (!res[i]) res[i] = res[i - 1];
        cout << res[i] << " ";
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/fct016_cprefix