#include <bits/stdc++.h>
#define int long long
#define double long double

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;

struct point {
    double x, y;

    friend istream &operator >> (istream &stream, point &u) {
        stream >> u.x >> u.y;
        return stream;
    }

    friend double dist(const point &u, const point &v) {
        return sqrt(pow(u.x - v.x, 2) + pow(u.y - v.y, 2));
    }

    friend point operator - (const point &u, const point &v) {
        point res;
        res.x = u.x - v.x;
        res.y = u.y - v.y;
        return res;
    }

    friend bool inside(const point &p, const point &u, const point &v) {
        return p.x >= min(u.x, v.x) && p.x <= max(u.x, v.x) && p.y >= min(u.y, v.y) && p.y <= max(u.y, v.y);
    }
} P, A, B, AB, H;

/*
    H is the foot of the perpendicular from P
    AB is the direction vector of the line connecting two points A and B
*/

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> P >> A >> B;
    AB = A - B;
    double t = (P.x * AB.x + P.y * AB.y - A.x * AB.x - A.y * AB.y) / (pow(AB.x, 2) + pow(AB.y, 2));
    H.x = AB.x * t + A.x;
    H.y = AB.y * t + A.y;
    if (inside(H, A, B)) cout << fixed << setprecision(10) << dist(P, H);
    else cout << fixed << setprecision(10) << min(dist(P, A), dist(P, B));
}

// https://oj.vnoi.info/problem/geo_h
