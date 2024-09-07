#include <bits/stdc++.h>
#define int long long
#define double long double

using namespace std;

const int N = 20;
const int MAX = 1ll << 11;
const int MOD = 998244353;

struct point {
    int x, y, z;

    point() : x(0), y(0), z(0) {}
    point(int a, int b, int c) : x(a), y(b), z(c) {}

    friend istream& operator >> (istream &stream, point &u) {
        stream >> u.x >> u.y >> u.z;
        return stream;
    }

    friend point operator - (const point &u, const point &v) {
        point res;
        res.x = v.x - u.x;
        res.y = v.y - u.y;
        res.z = v.z - u.z;
        return res;
    }

    friend point operator * (const point &u, const point &v) {
        point res;
        res.x = u.y * v.z - v.y * u.z;
        res.y = u.z * v.x - v.z * u.x;
        res.z = u.x * v.y - v.x * u.y;
        return res;
    }

    friend double length(const point &u) {
        return sqrt(pow(u.x, 2) + pow(u.y, 2) + pow(u.z, 2));
    }
};

int t;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> t;
    while (t--) {
        point A, B, C;
        cin >> A >> B >> C;
        point BC = B - C, AB = A - B;
        cout << fixed << setprecision(2) << length(AB * BC) / length(BC) << "\n";
    }

    cerr << "Run Finished";
}

// https://oj.vnoi.info/problem/fcb005_3dgeometry