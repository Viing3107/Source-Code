// code by viing3107
#pragma GCC optimize("O2", "O3", "Ofast")
#pragma target("avx", "avx2", "fma")
#include <bits/stdc++.h>
#define int long long
#define task "test"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define forEach(it, v) for(typeof v.begin() it = v.begin(), _e = v.end(); it != _e; it++)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

const int N = 1e5 + 5;
const int MOD = 20122007;

int n, res = 1, a, b;

int binaryExponentiation(int a, int n){
    int res = 1;
    for (; n; n >>= 1, a = (a * a) % MOD){
        if (n & 1) res = (res * a) % MOD;
    }
    return res;
}

bool check(int n){
    int tmp = sqrt(n);
    return tmp * tmp == n;
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
    for (int i = 1; i * i < n; i++){
        if (n % i == 0){
            a = (binaryExponentiation(3, i) - 1) % MOD;
            b = (binaryExponentiation(3, n / i) - 1) % MOD;
            a = (a * b) % MOD;
            res = (res * a) % MOD;
        }
    }
    if (check(n)){
        a = binaryExponentiation(3, sqrt(n)) - 1;
        res = (res * a) % MOD;
    }

    cout << res;

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/mystery