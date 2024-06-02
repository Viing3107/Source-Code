/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 15:26:51 - 02/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n;

struct matrix{
    int a[5][5];

    matrix(){
        memset(a, 0, sizeof a);
    }

    friend matrix operator* (matrix u, matrix v){
        matrix res;
        forUp(i, 1, 2, 1) forUp(j, 1, 2, 1) forUp(k, 1, 2, 1) (res.a[i][j] += u.a[i][k] * v.a[k][j]) %= MOD;
        return res;
    }

    friend matrix operator^ (matrix a, int n){
        matrix res;
        res.a[1][1] = 1;
        res.a[2][2] = 1;
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

    cin >> n;
    A.a[1][1] = 0;
    A.a[1][2] = 1;

    T.a[1][1] = 20;
    T.a[1][2] = 7;
    T.a[2][1] = 6;
    T.a[2][2] = 19;
    cout << (A * (T ^ n)).a[1][2];
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/errichto_matexp_stringmood

// Nháp và mọi thứ mình để ở đây : https://wbd.ms/share/v2/aHR0cHM6Ly93aGl0ZWJvYXJkLm1pY3Jvc29mdC5jb20vYXBpL3YxLjAvd2hpdGVib2FyZHMvcmVkZWVtL2E3YzQ0YWY0MGRkNzQyZTFhNWE0YWVjYTBmZGJkZWVhX0JCQTcxNzYyLTEyRTAtNDJFMS1CMzI0LTVCMTMxRjQyNEUzRF84ZjgzYjhmOS1lZjVmLTRkYjYtYjIxMC02MWI1MjcyMWY0NTQ=