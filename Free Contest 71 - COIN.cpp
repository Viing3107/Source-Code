/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 15:38:19 - 29/05/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 55;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int factorial[N], n, p, a[N], odd, even, result;

int binaryMultiplication(int a, int n){
    int res = 0;
    for(; n; n >>= 1, (a += a) %= MOD){
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

int C(int k, int n){
    return binaryMultiplication(factorial[n], binaryExponentiation(binaryMultiplication(factorial[k], factorial[n - k]), MOD - 2));
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> p;
    forUp(i, 1, n, 1){
        cin >> a[i];
        if (a[i] & 1) odd++;
        else even++;
    }
    factorial[0] = 1;
    forUp(i, 1, n, 1) factorial[i] = binaryMultiplication(factorial[i - 1], i);
    forUp(i, 0, even, 1){
        forUp(j, p, odd, 2){
            int multi = binaryMultiplication(C(i, even), C(j, odd));
            (result += multi) %= MOD;
        }
    }
    cout << result;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc071_coin

// Nháp và công thức mình để ở đây : https://wbd.ms/share/v2/aHR0cHM6Ly93aGl0ZWJvYXJkLm1pY3Jvc29mdC5jb20vYXBpL3YxLjAvd2hpdGVib2FyZHMvcmVkZWVtL2I2MmM2ZDQ5N2Q5NDRlZjViZTFiMjA3MTlmYmNlMWRiX0JCQTcxNzYyLTEyRTAtNDJFMS1CMzI0LTVCMTMxRjQyNEUzRF9kOGRhMDc1OS1lMGFmLTRmMWEtYTk0NS1mZmFkMWZlZDkyNTE=
