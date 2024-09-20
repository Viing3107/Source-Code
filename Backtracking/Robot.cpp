#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = (1ll << 21);

int n, res;

struct point {
    int x, y;

    friend istream &operator >> (istream &stream, point &p) {
        stream >> p.x >> p.y;
        return stream;
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

    friend bool operator < (const point &u, const point &v) {
        return u.x == v.x ? u.y < v.y : u.x < v.x;
    }
} a[N], e;

map<point, int> mp;

void backtrack(int i, point p, int n, int state) {
    if (i > n) {
        if (!state) mp[p]++;
        else res += mp[e - p];
        return;
    }
    backtrack(i + 1, p, n, state);
    backtrack(i + 1, p + a[i], n, state);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n >> e;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int m = n >> 1;
    backtrack(1, {0, 0}, m, 0);
    backtrack(m + 1, {0, 0}, n, 1);
    cout << res;
}

// https://marisaoj.com/problem/113
