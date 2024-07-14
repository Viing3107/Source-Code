/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 15:51:14 - 14/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define pi                      M_PI
#define eps                     1e-9
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

struct point{
    double x, y, v, omega, phi, r;
} A, B;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> A.x >> A.y >> A.v >> B.x >> B.y >> B.v;
    A.r = sqrt(A.x * A.x + A.y * A.y);
    B.r = sqrt(B.x * B.x + B.y * B.y);
    A.phi = atan2(A.y, A.x);
    B.phi = atan2(B.y, B.x);
    A.omega = A.v / A.r;
    B.omega = B.v / B.r;
    if (abs(A.phi - B.phi) <= eps) cout << 0;
    else if (abs(A.omega - B.omega) <= eps) cout << -1;
    else {
        double diff = B.phi - A.phi;
        if (A.omega < B.omega) diff = -diff;
        while (diff < 0) diff += 2 * pi;
        cout << fixed << setprecision(7) << diff / abs(A.omega - B.omega);
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/vmeclip