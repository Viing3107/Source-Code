/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 01:17:51 - 12/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 10;
const int MOD   = 1e15 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int t, n;

int multiplication(int a, int n){
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
        forUp(i, 1, 4, 1) forUp(j, 1, 4, 1) forUp(k, 1, 4, 1) (res.a[i][j] += multiplication(u.a[i][k], v.a[k][j])) %= MOD;
        return res;
    }

    friend matrix operator^ (matrix a, int n){
        matrix res;
        forUp(i, 1, 4, 1) res.a[i][i] = 1;
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

    A.a[1][1] = 1;
    A.a[1][2] = 2;
    A.a[1][3] = 3;
    A.a[1][4] = 3;

    T.a[1][3] = 1;
    T.a[2][1] = 1;
    T.a[2][3] = 1;
    T.a[3][2] = 1;
    T.a[3][3] = 1;
    T.a[3][4] = 1;
    T.a[4][4] = 1;

    cin >> t;
    while (t--){
        cin >> n;
        if (n == 1) cout << 1 << endl;
        else cout << (A * (T ^ (n - 2))).a[1][4] << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/vostribo

// 