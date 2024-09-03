#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = (1ll << 16) + 6;

struct point {
    int x, y;

    friend bool operator < (const point &u, const point &v) {
        return u.x == v.x ? u.y < v.y : u.x < v.x;
    }

    friend point operator + (const point &u, const point &v) {
        point res;
        res.x = u.x + v.x;
        res.y = u.y + v.y;
        return res;
    }

    friend point operator - (const point &u, const point &v) {
        point res;
        res.x = u.x - v.x;
        res.y = u.y - v.y;
        return res;
    }

    friend bool operator == (const point &u, const point &v) {
        return u.x == v.x && u.y == v.y;
    }
} a[N], p;

int n, result;
map<point, int> mp;

void backtrack(int i, int n, point u, int state) {
    if (i > n) {
        if (!state) mp[u]++;
        else result += mp[p - u];
        return;
    }
    backtrack(i + 1, n, u, state);
    backtrack(i + 1, n, u + a[i], state);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
    cin >> p.x >> p.y;
    int m = n / 2;
    backtrack(1, m, {0, 0}, 0);
    backtrack(m + 1, n, {0, 0}, 1);
    cout << result;
}

// https://oj.vnoi.info/problem/vector