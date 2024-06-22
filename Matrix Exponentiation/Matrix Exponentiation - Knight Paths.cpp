/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 08:55:56 - 12/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define state(x, y)             8 * (x - 1) + y

using namespace std;

const int N     = 100;
const int MOD   = 4294967296;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n;
int di[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dj[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int multiplitcation(int a, int n){
    int res = 0;
    for (; n; n >>= 1, (a += a) %= MOD){
        if (n & 1) (res += a) %= MOD;
    }
    return res;
}

struct matrix{
    int a[N][N];

    matrix(){
        memset(a, 0, sizeof a);
    }

    friend matrix operator* (matrix u, matrix v){
        matrix res;
        forUp(i, 1, 65, 1) forUp(j, 1, 65, 1) forUp(k, 1, 65, 1) (res.a[i][j] += multiplitcation(u.a[i][k], v.a[k][j])) %= MOD;
        return res;
    }

    friend matrix operator^ (matrix a, int n){
        matrix res;
        forUp(i, 1, 65, 1) res.a[i][i] = 1;
        for (; n; n >>= 1, a = a * a){
            if (n & 1) res = res * a;
        }
        return res;
    }
} A, T;

bool inside(int x, int y){
    return x >= 1 && x <= 8 && y >= 1 && y <= 8;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    A.a[1][1] = 1;

    forUp(i, 1, 8, 1){
        forUp(j, 1, 8, 1){
            forUp(k, 0, 7, 1){
                int i1 = i + di[k];
                int j1 = j + dj[k];
                if (inside(i1, j1)) T.a[state(i1, j1)][state(i, j)] = 1;
            }
            T.a[state(i, j)][65] = 1;
        }
    }
    T.a[65][65] = 1;

    A = A * (T ^ (n + 1));
    cout << A.a[1][65];
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/errichto_matexp_knightpaths

// Nháp và mọi thứ mình để ở đây : https://wbd.ms/share/v2/aHR0cHM6Ly93aGl0ZWJvYXJkLm1pY3Jvc29mdC5jb20vYXBpL3YxLjAvd2hpdGVib2FyZHMvcmVkZWVtLzA4ODliMGY5YmQ0OTRkYjhhODYzMzhiMjhhNGMwMmQzX0JCQTcxNzYyLTEyRTAtNDJFMS1CMzI0LTVCMTMxRjQyNEUzRF84MWQ5MjRhNC1lYmExLTQ2ZTUtOTJmNS0yMWM0YjIwNTI1NzU=