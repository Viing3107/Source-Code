/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 08:31:25 - 24/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e5 + 5;
const int LIM           = 1e6 + 6;
const int PRIME_SIZE    = 78497;

int a, b, q;
int p[] = {3, 5, 7, 11, 13, 17, 19, 23};
vector<int> prime, lpf;
map<pair<int, int>, int> mp;

void sieve(int n){
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);
    forUp(x, 3, n, 2){
        if (lpf[x] == 2) prime.push_back(lpf[x] = x);
        for (int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; i++)
            lpf[prime[i] * x] = prime[i];
    }
}

bool isPrime(int x){
    return x >= 2 && lpf[x] == x;
}

int binaryExponentiation(int a, int n){
    int res = 1;
    for (; n; n >>= 1, a *= a){
        if (n & 1) res *= a;
    }
    return res;
}

int f(int x){
    int res = 0;
    forUp(i, 0, PRIME_SIZE - 1, 1){
        if (prime[i] * prime[i] > x) break;
        forUp(j, 0, 7, 1){
            if (binaryExponentiation(prime[i], p[j] - 1) > x) break;
            res++;
        }
    }
    res += upper_bound(prime.begin(), prime.end(), x) - prime.begin() - 1;
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    sieve(LIM);
    cin >> q;
    while (q--){
        cin >> a >> b;
        if (mp[make_pair(a, b)]) cout << mp[make_pair(a, b)] << "\n";
        else mp[make_pair(a, b)] = f(b) - f(a - 1);
        cout << f(b) - f(a - 1) << "\n";
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 