/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 16:57:22 - 01/06/2024

*/
#pragma GCC                     optimize("O3", "unroll-loops")
#pragma GCC                     target("avx2", "bmi", "bmi2", "lzcnt", "popcnt")
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define gcd(a, b)               __gcd(a, b)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 4294967296;

string s;
int p, q, result, tmp;
vector<pair<char, int>> v;

int binaryMultiplication(int a, int n){
    int res = 0;
    for (; n; n >>= 1, (a += a) %= INF){
        if (n & 1) (res += a) % INF;
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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> s;
    forUp(i, 0, s.size() - 1, 1){
        if (s[i] == '/'){
            p = stoll(s.substr(0, i + 1));
            q = stoll(s.substr(i + 1, s.size() - i));
        }
    }
    tmp = gcd(p, q);
    p /= tmp;
    q /= tmp;

    while (p != 1 && q != 1){
        if (p > q){
            v.push_back({'R', p / q});
            p %= q;
        }
        else{
            v.push_back({'L', q / p});
            q %= p;
        }
    }
    if (p > q){
        v.push_back({'R', p / q - 1});
        p %= q;
    }
    else{
        v.push_back({'L', q / p - 1});
        q %= p;
    }
    reverse(v.begin(), v.end());
    result = 1;
    for (auto it : v){
        if (it.first == 'L') result *= binaryExponentiation(2, it.second) % INF;
        else result = (binaryMultiplication(result + 1, binaryExponentiation(2, it.second)) - 1) % INF;
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

// https://oj.vnoi.info/problem/fc035_rational