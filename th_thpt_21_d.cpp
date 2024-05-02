// code by viing3107
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

const int N     = 1e2 + 2;
const int LIM   = 1e6;
const int M     = 78497;

int L, R, answer, l, r, m, tmp;
int p[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
vector<int> prime, lpf;

int binaryExponentiation(int a, int n){
    int res = 1;
    for (; n; n >>= 1, a *= a){
        if (n & 1) res *= a;
    }
    return res;
}

void sieve(int n){
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);
    forUp(x, 3, n, 2){
        if (lpf[x] == 2) prime.push_back(lpf[x] = x);
        for (int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; i++)
            lpf[prime[i] * x] = prime[i];
    }
}

bool isPrime(int n){
    return n >= 2 && lpf[n] == n;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> L >> R;
    sieve(LIM);
    forUp(i, 0, 10, 1){
        forUp(j, 0, M, 1){
            tmp = binaryExponentiation(prime[j], p[i] - 1);
            if (tmp >= L){
                if (tmp <= R) answer++;
                else break;
            }
        }
    }
    cout << answer;

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 
