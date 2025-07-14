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

int n, m, p;

struct passenger {
    int id, time;

    friend istream& operator >> (istream &stream, passenger &p) {
        stream >> p.id >> p.time;
        return stream;
    }
};

vector<int> a[N];

bool f(int x) {
    int cnt = 0;
    forUp (i, 1, p, 1) {
        for (auto &t : a[i]) if (t <= x) cnt++;
        x++;
    }
    return cnt >= m;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m >> p;
    forUp (i, 1, n, 1) {
        passenger x;
        cin >> x;
        a[x.id].push_back(x.time);
    }
    int l = 0, r = 1e9;
    while (r - l > 1) {
        int m = l + r >> 1;
        if (f(m)) r = m;
        else l = m;
    }
    cout << r;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 Viing3107

*/

// https://oj.vnoi.info/problem/fcb046_bus
