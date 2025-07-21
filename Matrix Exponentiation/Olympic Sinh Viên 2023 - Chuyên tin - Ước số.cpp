/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 14:47:35 - 21/07/2025

*/

#include                        <bits/stdc++.h>
#define task                    "test"
#define int                     long long
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)

using namespace std;

int a, b, MOD, n;

/*
Tính chất: GCD(f[a], f[b]) = f[gcd(a, b)]

*/

int binaryMultiplication(int a, int b) {
    if (a < b) swap(a, b);
    int res = 0;
    for (; b; b >>= 1, (a += a) %= MOD) if (b & 1) (res += a) %= MOD;
    return res;
}

struct matrix {
    int a[3][3];

    matrix() {memset(a, 0, sizeof a);}
    
    friend matrix operator* (const matrix &u, const matrix &v) {
        matrix res;
        forUp(i, 1, 2, 1) forUp(j, 1, 2, 1) forUp(k, 1, 2, 1) (res.a[i][j] += binaryMultiplication(u.a[i][k], v.a[k][j])) %= MOD;
        return res;
    }

    friend matrix operator^ (matrix &a, int n) {
        matrix res;
        res.a[1][1] = res.a[2][2] = 1;
        for (; n; n >>= 1, a = a * a) if (n & 1) res = res * a;
        return res;
    }
} T;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> a >> b >> MOD;
    n = __gcd(a, b);
    T.a[1][1] = T.a[1][2] = T.a[2][1] = 1;
    cout << (T ^ (n - 1)).a[1][1];
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/olp_ct23_gcd