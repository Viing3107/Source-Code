/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 14:38:12 - 28/05/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define pi                      M_PI
#define eps                     1e-6

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n;

struct point{
    double x, y, angle;

    friend bool operator < (point u, point v){
        return u.angle < v.angle;
    }
} a[N];

double result = 360;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    forUp(i, 1, n, 1){
        cin >> a[i].x >> a[i].y;
        if (a[i].x >= 0 && a[i].y >= 0) a[i].angle = atan2(a[i].y,  a[i].x) / pi * 180;
        else if (a[i].x <= 0 && a[i].y >= 0) a[i].angle = atan2(a[i].y,  a[i].x) / pi * 180;
        else if (a[i].x <= 0 && a[i].y <= 0) a[i].angle = atan2(a[i].y,  a[i].x) / pi * 180;
        else a[i].angle = atan2(a[i].y,  a[i].x) / pi * 180;
    }
    forUp(i, 1, n, 1) if (a[i].angle < 0) a[i].angle += 360;
    sort(a + 1, a + n + 1);
    a[0] = a[n];
    forUp(i, 1, n, 1) result = min(result, abs(a[i].angle - a[i - 1].angle));
    result = cos(result / 180 * pi);
    cout << fixed << setprecision(4) << result;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb020_radian

// Nháp và mọi thứ mình để ở đây : https://wbd.ms/share/v2/aHR0cHM6Ly93aGl0ZWJvYXJkLm1pY3Jvc29mdC5jb20vYXBpL3YxLjAvd2hpdGVib2FyZHMvcmVkZWVtL2QzNjBjMzEyOWZmOTQwNDRiOWJlOGZiMGY5NGRiNTJjX0JCQTcxNzYyLTEyRTAtNDJFMS1CMzI0LTVCMTMxRjQyNEUzRF9mMzZmMzE2NC0xYTcyLTQ1MTQtYWFiOS00NzE4ZTk3MzAwMWM=