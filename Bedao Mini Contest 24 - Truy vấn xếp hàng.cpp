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
const int    BASE       = 311;
const int    BLOCK_SIZE = 320;
const double EPS        = 1e-6;
const int    N          = 3e5 + 5;
const int    VAL        = 1e6 + 6;
const int    MOD        = 1e9 + 7;
const int    INF        = 0x3f3f3f3f3f3f3f3f;

struct Element {
    int x, id;

    friend bool operator < (const Element &u, const Element &v) {
        return u.x < v.x;
    }
};

multiset<Element> s;
int q, x, v, type, cnt, lazy;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> q;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            cnt++;
            s.insert({x - lazy, cnt});
        }
        else if (type == 2) {
            cin >> v;
            lazy += v;
        }
        else {
            cin >> x;
            s.erase({x - lazy, 0});
        }
    }
    // for (auto &e : s) cout << e.x + lazy << " " << e.id << endl;
    vector<Element> v;
    for (auto &e : s) v.push_back(e);
    sort(ALL(v), [&](const Element &u, const Element &v) -> bool {
        return u.id < v.id;
    });
    cout << SZ(v) << endl;
    for (auto &e : v) cout << e.x + lazy << " ";

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/bedao_m24_c