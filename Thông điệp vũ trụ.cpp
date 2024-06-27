/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 20:37:34 - 23/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e7 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int m;
char mark[50];
string result;
vector<int> prime, lpf;

void sieve(int n){
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);
    forUp(x, 3, n, 2){
        if (lpf[x] == 2) prime.push_back(lpf[x] = x);
        for (int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; i++)
            lpf[prime[i] * x] = prime[i];
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    sieve(N);
    forUp(i, 65, 90, 1) mark[i - 65] = char(i);
    cin >> m;
    for (int idx = 0; idx < prime.size(); idx++){
        if (m % prime[idx] == 0) result += mark[prime[idx] % 26];
    }
    if (!result.size()) result += mark[m % 26];
    sort(result.begin(), result.end());
    cout << result;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/codetour24_c2_b