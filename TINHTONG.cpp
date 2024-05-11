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

int a, n, MOD;

int binaryMultiplication(int a, int n, int MOD){
    int res = 0;
    for (; n; n >>= 1, (a += a) %= MOD){
        if (n & 1) (res += a) % MOD;
    }
    return res;
}

int binaryExponentiation(int a, int n, int MOD){
    int res = 1;
    for (; n; n >>= 1, a = binaryMultiplication(a, a, MOD)){
        if (n & 1) res = binaryMultiplication(res, a, MOD);
    }
    return res;
}

int solve(int a, int n, int MOD){
    if (n == 0) return 0;
    if (n == 1) return a % MOD;
    int k = n / 2;
    int tmp = solve(a, k, MOD);
    if (n % 2 == 0) return binaryMultiplication(binaryExponentiation(a, k, MOD) + 1, tmp, MOD);
    else return (binaryMultiplication(binaryExponentiation(a, k, MOD) + 1, tmp, MOD) + binaryExponentiation(a, n, MOD)) % MOD;
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
    cout << (solve(a, n, MOD) + 1) % MOD;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 