/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:20:02 - 28/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define pi                      M_PI
#define MASK(i)                 (1ll << (i))
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e5 + 5;
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int t, r, x;

double radian(double degree) {return degree * pi / 180;}
double degree(double radian) {return radian / pi * 180;}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> t;
    while (t--) {
        cin >> r >> x;
        double AC = r * sqrt(2 - 2 * cos(radian(144)));
        double AE = r * sqrt(2 - 2 * cos(radian(72)));
        double AEH = 0.5 * AE * x * sin(radian(108));
        double TriangleOAE = 0.5 * r * r * sin(radian(72));
        double ArcOAE = 0.2 * pi * r * r;
        double VP = ArcOAE - TriangleOAE;
        double AEC = 0.5 * AC * AC * sin(radian(36));
        double CDE = 0.5 * AE * AE * sin(radian(108));
        
        // cout << AC << endl;
        // cout << AE << endl;
        // cout << AEH << endl;
        // cout << TriangleOAE << endl;
        // cout << ArcOAE << endl;
        // cout << VP << endl;
        // cout << AEC << endl;
        // cout << CDE << endl;
        cout << fixed << setprecision(10) << VP + AEH + 2 * AEC + CDE << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bedao_r02_geometry2