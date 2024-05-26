/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:29:41 - 26/05/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n;
double p, dp[N][2];

struct matrix{
    double a[5][5];

    matrix(){
        memset(a, 0, sizeof a);
    }

    friend matrix operator* (matrix u, matrix v){
        matrix res;
        forUp(i, 1, 2, 1) forUp(j, 1, 2, 1) forUp(k, 1, 2, 1) res.a[i][j] += u.a[i][k] * v.a[k][j];
        return res;
    }

    friend matrix operator^ (matrix a, int n){
        matrix res;
        forUp(i, 1, 2, 1) res.a[i][i] = 1.0;
        for (; n; n >>= 1, a = a * a){
            if (n & 1) res = res * a;
        }
        return res;
    }
} A, T;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    cin >> n >> p;

    A.a[1][1] = 1 - p;
    A.a[1][2] = p;
    A.a[2][1] = 1;

    T.a[1][1] = 1 - p;
    T.a[1][2] = p;
    T.a[2][1] = p;
    T.a[2][2] = 1 - p;

    A = A * (T ^ (n - 1));

    cout << fixed << setprecision(10) << A.a[1][1];    

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/errichto_matexp_randmood

// Nháp và công thức mình sử dụng : https://wbd.ms/share/v2/aHR0cHM6Ly93aGl0ZWJvYXJkLm1pY3Jvc29mdC5jb20vYXBpL3YxLjAvd2hpdGVib2FyZHMvcmVkZWVtLzYwMmY1MGQ2OTg1OTQzMmViNzM1ZDkxNzQ5Y2I0NmQ0X0JCQTcxNzYyLTEyRTAtNDJFMS1CMzI0LTVCMTMxRjQyNEUzRF8zOWUzZWI5YS0yYzI5LTQ0MDMtODBmYy1lNzBiNjU0ZDU0Nzc=