#include <bits/stdc++.h>
#define double long double

using namespace std;

struct line {
    double a, b, c;

    friend ostream& operator << (ostream &stream, const line &u) {
        stream << fixed << setprecision(9) << u.a << " " << u.b << " " << u.c;
        return stream;
    }
} AB, AC, L1, L2;

struct point {
    double x, y;

    friend istream& operator >> (istream &stream, point &u) {
        stream >> u.x >> u.y;
        return stream;
    }

    friend line operator - (const point &u, const point &v) {
        line res;
        res.a = v.y - u.y;
        res.b = u.x - v.x;
        res.c = v.x * u.y - u.x * v.y;
        return res;
    }
} A, B, C;

void solve() {
    double val1 = L1.a * B.x + L1.b * B.y + L1.c;
    double val2 = L1.a * C.x + L1.b * C.y + L1.c;
    if (val1 * val2 < 0) cout << L1;
    else cout << L2;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> A >> B >> C;
    AB = A - B;
    AC = A - C;
    L1.a = AB.a / sqrt(pow(AB.a, 2) + pow(AB.b, 2)) - AC.a / sqrt(pow(AC.a, 2) + pow(AC.b, 2));
    L1.b = AB.b / sqrt(pow(AB.a, 2) + pow(AB.b, 2)) - AC.b / sqrt(pow(AC.a, 2) + pow(AC.b, 2));
    L1.c = AB.c / sqrt(pow(AB.a, 2) + pow(AB.b, 2)) - AC.c / sqrt(pow(AC.a, 2) + pow(AC.b, 2));

    L2.a = AB.a / sqrt(pow(AB.a, 2) + pow(AB.b, 2)) + AC.a / sqrt(pow(AC.a, 2) + pow(AC.b, 2));
    L2.b = AB.b / sqrt(pow(AB.a, 2) + pow(AB.b, 2)) + AC.b / sqrt(pow(AC.a, 2) + pow(AC.b, 2));
    L2.c = AB.c / sqrt(pow(AB.a, 2) + pow(AB.b, 2)) + AC.c / sqrt(pow(AC.a, 2) + pow(AC.b, 2));

    solve();

    cerr << "Run Finished";
}

// https://oj.vnoi.info/problem/geo_d
