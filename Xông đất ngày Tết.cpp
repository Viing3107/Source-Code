/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 16:40:12 - 22/07/2025

*/

#include                        <iostream>
#include                        <math.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)

using namespace std;

const int       N           = 1e5 + 5;
const int       MOD         = 1e5 + 3;

int t, m, n, pn, pm, p[N];

// Định lí Lucas

int binMul(int a, int b) {
    if (a < b) swap(a, b);
    int res = 0;
    for (; b; b >>= 1, (a += a) %= MOD) if (b & 1) (res += a) %= MOD;
    return res;
}

int binExp(int a, int n) {
    int res = 1;
    for (; n; n >>= 1, (a *= a) %= MOD) if (n & 1) (res *= a) %= MOD;
    return res;
}

int comb(int a, int b) {
    if (a > b) return 0;
    return (p[b] * binExp(binMul(p[a], p[b - a]), MOD - 2)) % MOD;
}

int calc() {
    int res = 1;
    forDown(i, 3, 0, -1) {
        pn = n / pow(MOD, i);
        n %= (int) pow(MOD, i);
        pm = m / pow(MOD, i);
        m %= (int) pow(MOD, i);
        if (pn > pm) return 0;
        (res *= comb(pn, pm)) %= MOD;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    p[0] = 1;
    forUp(i, 1, 100002, 1) p[i] = (p[i - 1] * i) % MOD;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        m = m - n + 1;
        cout << calc() << endl;    
    }
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/c11tct