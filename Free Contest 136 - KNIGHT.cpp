/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 00:37:43 - 26/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e6 + 6;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, m, factorial[N];

int binaryMultiplication(int a, int n){
    int res = 0;
    for (; n; n >>= 1, (a += a) %= MOD){
        if (n & 1) (res += a) %= MOD;
    }
    return res;
}

int binaryExponentiation(int a, int n){
    int res = 1;
    for (; n; n >>= 1, a = binaryMultiplication(a, a)){
        if (n & 1) res = binaryMultiplication(res, a);
    }
    return res;
}

int C(int k, int n){ // n! / (k! * (n - k)!)
    return binaryMultiplication(factorial[n], binaryExponentiation(binaryMultiplication(factorial[k], factorial[n - k]), MOD - 2));
}

// nCk = (n - 1)Ck + (n - 1)C(k - 1)

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m;
    factorial[0] = 1;
    forUp(i, 1, 1e6, 1) factorial[i] = (factorial[i - 1] * i) % MOD;
    if (n > m) swap(n, m);
    if ((n + m) % 3) cout << 0;
    else cout << C(m - (n + m) / 3, (n + m) / 3);
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc136_knight