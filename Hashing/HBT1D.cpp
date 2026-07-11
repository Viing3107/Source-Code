/*
    Author : Do Quang Vinh
    Vietnam National University - Ha Noi
    Created : 17:52:19 - 21/11/2025

*/

#include <bits/stdc++.h>
#define endl                   "\n"
#define task                   "test"
#define int                    long long
#define double                 long double
#define gcd(x, y)              __gcd(x, y)
#define MASK(i)                (1ll << (i))
#define BIT(i, n)              ((n) >> (i) & 1)
#define SZ(v)                  (int)(v).size()
#define lcm(x, y)              x / gcd(x, y) * y
#define ALL(v)                 (v).begin(), (v).end()
#define LOG(x)                 (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)   for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step) for (int i = (l); i >= (r); i += step)

using namespace std;

const int    LEVEL      = 20;
const int    BLOCK_SIZE = 320;
const double EPS        = 1e-6;
const int    N          = 3e6 + 5;
const int    M          = 3;
const int    VAL        = 1e6 + 6;
const int    INF        = 0x3f3f3f3f3f3f3f3f;
const int    MOD[]     = {1000000000039, 10000000000037, 100000000000031};

struct Tuple {
    int h1, h2, h3;

    Tuple(){};
    Tuple(int x, int y, int z) : h1(x % MOD[0]), h2(y % MOD[1]), h3(z % MOD[2]) {}

    friend Tuple operator + (const Tuple &u, const Tuple &v) {
        return Tuple(u.h1 + v.h1, u.h2 + v.h2, u.h3 + v.h3);
    }

    friend bool operator < (const Tuple &u, const Tuple &v) {
        return (u.h1 != v.h1) ? (u.h1 < v.h1) : ((u.h2 != v.h2) ? (u.h2 < v.h2) : (u.h3 < v.h3));
    }
} f[N];

int q, n;
string s;

int hashCode(int i) {
    int res = 0;
    forUp (j, 0, SZ(s) - 1, 1) res = (res * 10 + s[j] - '0') % MOD[i];
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    f[0] = Tuple(1, 1, 1);
    f[1] = Tuple(1, 1, 1);
    forUp (i, 2, N - 1, 1) f[i] = f[i - 1] + f[i - 2];
    sort(f, f + N);
    cin >> q;
    while (q--) {
        cin >> s;
        cout << (binary_search(f, f + N, Tuple(hashCode(0), hashCode(1), hashCode(2))) ? "Yes\n" : "No\n");
    }

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/hbt1d