/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 00:19:46 - 17/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 5;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int a, b, MOD, n;

int binaryMultiplication(int a, int n){
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
        forUp(i, 1, 2, 1) forUp(j, 1, 2, 1) forUp(k, 1, 2, 1) (res.a[i][j] += binaryMultiplication(u.a[i][k], v.a[k][j])) %= MOD;
        return res;
    }

    friend matrix operator^ (matrix a, int n){
        matrix res;
        forUp(i, 1, 2, 1) res.a[i][i] = 1;
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

    cin >> a >> b >> MOD >> n;

    if (n == 1) cout << a % MOD;
    else if (n == 2) cout << b % MOD;
    else{
        A.a[1][1] = a + binaryMultiplication(b, b);
        A.a[1][2] = 1;

        T.a[1][1] = b;
        T.a[2][1] = a;
        T.a[2][2] = 1;

        cout << (A * (T ^ (n - 3))).a[1][1];    
    }

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://nhpoj.net/problem/P315?fbclid=IwZXh0bgNhZW0CMTAAAR0Mf6ISxQbdKGqraZbeIUp4MQml-SiEd-fuFvvBF-zUdGV3R1pQgz2hZZ8_aem_fgpROo9XewGVdwV4AGuwNQ