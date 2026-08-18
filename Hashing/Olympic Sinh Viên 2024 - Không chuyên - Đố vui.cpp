/*
    Author: Do Quang Vinh
    VNU University of Engineering and Technology, Hanoi, Vietnam
    Created: 16:04:16 17/08/2026

*/

#include <bits/stdc++.h>
#define endl                   "\n"
#define task                   "test"
#define int                    long long
#define double                 long double
#define gcd(x, y)              __gcd(x, y)
#define MASK(i)                (1ll << (i))
#define SZ(v)                  (int)(v).size()
#define BIT(i, n)              ((n) >> (i) & 1)
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
const int    N          = 2e6 + 5;
const int    VAL        = 1e6 + 6;
const int    INF        = 0x3f3f3f3f3f3f3f3f;
const int    MOD[]      = {10000019, 100000007, 1000000007};

int n, m, pos;
string s, res;

struct Tuple {
    int v1, v2, v3;

    Tuple() {};
    Tuple(int x, int y, int z) {
        v1 = (x % MOD[0] + MOD[0]) % MOD[0];
        v2 = (y % MOD[1] + MOD[1]) % MOD[1];
        v3 = (z % MOD[2] + MOD[2]) % MOD[2];
    }

    friend Tuple operator+ (const Tuple &u, const Tuple &v) {
        return Tuple(u.v1 + v.v1, u.v2 + v.v2, u.v3 + v.v3);
    }

    friend Tuple operator- (const Tuple &u, const Tuple &v) {
        return Tuple(u.v1 - v.v1, u.v2 - v.v2, u.v3 - v.v3);
    }

    friend Tuple operator* (const Tuple &u, const Tuple &v) {
        return Tuple(u.v1 * v.v1, u.v2 * v.v2, u.v3 * v.v3);
    }

    friend bool operator== (const Tuple &u, const Tuple &v) {
        return u.v1 == v.v1 && u.v2 == v.v2 && u.v3 == v.v3;
    }

    friend bool operator!= (const Tuple &u, const Tuple &v) {
        return u.v1 != v.v1 || u.v2 != v.v2 || u.v3 != v.v3;
    }

    friend Tuple operator+ (const Tuple &u, const int x) {
        return Tuple(u.v1 + x, u.v2 + x, u.v3 + x);
    }

    friend Tuple operator* (const Tuple &u, const int x) {
        return Tuple(u.v1 * x, u.v2 * x, u.v3 * x);
    }

    friend ostream& operator << (ostream &stream, const Tuple &u) {
        stream << u.v1 << " " << u.v2 << " " << u.v3;
        return stream;
    }
} hashS[N], p[N], foundHash(-1, -1, -1);

Tuple get(int l, int r) {
    return hashS[r] - hashS[l - 1] * p[r - l + 1];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> s;

    if (n % 2 == 0) cout << "No Solution";
    else {
        m = n >> 1;
        s = " " + s;
        p[0] = Tuple(1, 1, 1);
        forUp (i, 1, n, 1) p[i] = p[i - 1] * BASE;
        forUp (i, 1, n, 1) hashS[i] = hashS[i - 1] * BASE + (s[i] - 'A' + 1);
        // forUp (i, 1, n, 1) cout << p[i] << endl;
        // forUp (i, 1, n, 1) cout << hashS[i] << " \n"[i == n];
        forUp (i, 1, n, 1) {
            Tuple curHash(-1, -1, -1);
            if (i <= m + 1) {
                if (get(1, i - 1) * p[m - i + 1] + get(i + 1, m + 1) == get(m + 2, n)) curHash = get(m + 2, n);
            }
            if (i >= m + 1) {
                if (get(1, m) == get(m + 1, i - 1) * p[n - i] + get(i + 1, n)) curHash = get(1, m);
            }

            if (curHash != Tuple(-1, -1, -1)) {
                if (!pos) {
                    pos = i;
                    foundHash = curHash;
                }
                else if (curHash != foundHash) {
                    cout << "Multiple Solutions";
                    return 0;
                }
            }
        }
        if (pos) {
            s.erase(s.begin() + pos);
            string t;
            forUp (i, 1, m, 1) t += s[i];
            cout << t;
        }
        else cout << "No Solution";
    }

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/olp_kc24_string