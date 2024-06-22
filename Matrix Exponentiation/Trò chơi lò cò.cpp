/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 11:28:48 - 14/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)

using namespace std;

const int N     = 5;

int n, M;

struct matrix{
    int a[N][N];
    
    matrix(){
        memset(a, 0, sizeof a);
    }

    friend matrix operator* (matrix u, matrix v){
        matrix res;
        forUp(i, 1, 3, 1) forUp(j, 1, 3, 1) forUp(k, 1, 3, 1) (res.a[i][j] += u.a[i][k] * v.a[k][j]) %= M;
        return res;
    }

    friend matrix operator^ (matrix a, int n){
        matrix res;
        forUp(i, 1, 3, 1) res.a[i][i] = 1;
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

    cin >> n >> M;

    if (n == 1) cout << 1 % M;
    else if (n == 2) cout << 2 % M;
    else if (n == 3) cout << 4 % M;
    else{
        A.a[1][1] = 1;
        A.a[1][2] = 2;
        A.a[1][3] = 4;

        T.a[1][3] = 1;
        T.a[2][1] = 1;
        T.a[2][3] = 1;
        T.a[3][2] = 1;
        T.a[3][3] = 1;

        cout << (A * (T ^ (n - 3))).a[1][3];    
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/dhloco

// https://wbd.ms/share/v2/aHR0cHM6Ly93aGl0ZWJvYXJkLm1pY3Jvc29mdC5jb20vYXBpL3YxLjAvd2hpdGVib2FyZHMvcmVkZWVtLzQ5MzNkYzA3MDIwMDQ4MWJiZWQyYzkzYmQwNGFiMDg3X0JCQTcxNzYyLTEyRTAtNDJFMS1CMzI0LTVCMTMxRjQyNEUzRF82ZjUzNTU3MC0xNzY5LTRjNzQtOWQ2Mi1kMmI0NGIwZTRkYWY=