/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:04:08 - 18/08/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define SZ(v)                   (int) v.size()
#define all(v)                  v.begin(), v.end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e5 + 5;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int BLOCK_SIZE    = sqrt(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, minVal;

struct point {
    int x, y;

    int dist (const point &u, const point &v) {return abs(u.x - v.x) + abs(u.y - v.y);}
} a[N], answer;

int f(const point &u, int state) {
    int res = 0;
    forUp(i, 1, n, 1) res += state ? a->dist({u.x, 0}, {a[i].x, 0}) : a->dist({0, u.y}, {0, a[i].y});
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

    cin >> n;
    forUp(i, 1, n, 1) cin >> a[i].x >> a[i].y;
    int lX = 1, rX = 1e9, lY = 1, rY = 1e9;
    while (rX - lX > 1) {
        int mX = lX + rX >> 1;
        if (f({mX, 0}, 1) < f({mX + 1, 0}, 1)) rX = mX;
        else lX = mX;
    }
    minVal = INF;
    forUp(i, lX, rX, 1) {
        int val = f({i, 0}, 1);
        if (val < minVal) {
            minVal = val;
            answer.x = i;
        }
    }

    while (rY - lY > 1) {
        int mY = lY + rY >> 1;
        if (f({0, mY}, 0) < f({0, mY + 1}, 0)) rY = mY;
        else lY = mY;
    }
    minVal = INF;
    forUp(i, lY, rY, 1) {
        int val = f({0, i}, 0);
        if (val < minVal) {
            minVal = val;
            answer.y = i;
        }
    }
    cout << f(answer, 1) + f(answer, 0);
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb025_spot