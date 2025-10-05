/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:02:36 - 05/10/2025

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
const int       N           = 1e6 + 5;
const int       VAL         = 1e6 + 6;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int MOD[] = {1000000007, 1000000009};
int n, m, q, hashA[2][N], hashB[2][N], p[2][N];
string a, b;

int getHash(int type, int i, int l, int r) {
    if (!type) return ((hashA[i][r] - hashA[i][l - 1] * p[i][r - l + 1]) % MOD[i] + MOD[i]) % MOD[i];
    else return ((hashB[i][r] - hashB[i][l - 1] * p[i][r - l + 1]) % MOD[i] + MOD[i]) % MOD[i];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m >> a >> b;
    p[0][0] = p[1][0] = 1;
    forUp (i, 0, 1, 1) forUp (j, 1, 1e6, 1) p[i][j] = (p[i][j - 1] * BASE) % MOD[i];
    a = " " + a;
    b = " " + b;
    forUp (i, 0, 1, 1) forUp (j, 1, n, 1) hashA[i][j] = (hashA[i][j - 1] * BASE + (int) a[j]) % MOD[i];
    forUp (i, 0, 1, 1) forUp (j, 1, m, 1) hashB[i][j] = (hashB[i][j - 1] * BASE + (int) b[j]) % MOD[i];

    cin >> q;
    while (q--) {
        int l, r, u, v;
        cin >> l >> r >> u >> v;
        int L = 1, R = min(r - l + 1, v - u + 1), length = 0;
        while (R - L >= 0) {
            int M = L + R >> 1;
            if (getHash(0, 0, l, l + M - 1) == getHash(1, 0, u, u + M - 1) &&
                getHash(0, 1, l, l + M - 1) == getHash(1, 1, u, u + M - 1)
            ) {
                length = M;
                L = M + 1;
            }
            else R = M - 1;
        }
        if (length == min(r - l + 1, v - u + 1)) {
            if (r - l + 1 > v - u + 1) cout << '>';
            else if (r - l + 1 < v - u + 1) cout << '<';
            else cout << '=';
        }
        else {
            if (a[l + length] < b[u + length]) cout << '<';
            else if (a[l + length] > b[u + length]) cout << '>';
            else cout << '=';
        }
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/vostr