/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:35:52 - 01/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define pi                      acos(-1)
#define eps                     1e-1

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int t;
double dist, l, d, x, theta;

double TAN(double x){
	return tan(x / 180.0 * pi);
}

int solve(double l, int state){
    if (state){
        if (theta < 90) dist = d / TAN(90 - theta);
        else dist = d / TAN(theta - 90);
    }
    else{
        if (theta < 90) dist = d * TAN(theta);
        else dist = -d * TAN(theta);
    }
    if (dist - l > eps) return 0;
    return 1 + solve(l - dist, state ^ 1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".ans", "w", stdout);
    }

    cin >> t;
    while(t--){
        cin >> l >> d >> x >> theta;
        if (theta == 90) cout << 0 << endl;
        else{
            if (theta < 90) dist = x * TAN(theta);
            else dist = (x - d) * TAN(theta);
            if (dist - l > eps) cout << 0 << endl;
            else cout << 1 + solve(l - dist, 1) << endl;
        }
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb033_reflect