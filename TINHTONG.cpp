/*

    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh

*/
#pragma GCC                     optimize("O2", "O3", "Ofast")
#pragma                         target("avx", "avx2", "fma")
#include                        <bits/stdc++.h>
#define int                     long long
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define gcd(a, b)               __gcd(a, b)
#define lcm(a, b)               a / gcd(a, b) * b

using namespace std;

const int N     = 1e5 + 5;
const int LIM   = 1e6;
const int M     = 78497;

int a, n, MOD = 1e9 + 7;

struct matrix{
    int a[5][5];
    matrix(){
        forUp(i, 1, 2, 1) forUp(j, 1, 2, 1) a[i][j] = 0;
    }
    friend matrix operator* (matrix u, matrix v){
        matrix res;
        forUp(i, 1, 2, 1) forUp(j, 1, 2, 1) forUp(k, 1, 2, 1) (res.a[i][j] += u.a[i][k] * v.a[k][j]) %= MOD;
        return res;
    }
} A, B, res;

matrix binaryExponentiation(matrix a, int n){
    matrix res;
    res.a[1][1] = res.a[2][2] = 1;
    for (; n; n >>= 1, a = a * a){
        if (n & 1) res = res * a;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> a >> n >> MOD;
    A.a[1][1] = a + 1;
    A.a[1][2] = a;
    A.a[2][1] = A.a[2][2] = 1;
    B.a[1][1] = 1;
    B.a[2][1] = B.a[2][2] = a;
    cout << (A * binaryExponentiation(B, n - 1)).a[1][1];

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc038_tinhtong