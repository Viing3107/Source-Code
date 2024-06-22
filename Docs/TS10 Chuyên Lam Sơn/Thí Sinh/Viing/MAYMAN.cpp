/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 17:22:52 - 21/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "MAYMAN"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 3e5 + 5;
const int LIM   = 1e6 + 6;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, a[N], result;
map<int, int> mp;
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

int muldiv(int n){
    int res = 1;
    for (int y = lpf[n]; n != 1; y = lpf[n]){
        res *= y;
        while (n % y == 0) n /= y;
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

    sieve(LIM);
    cin >> n;
    forUp(i, 1, n, 1){
        cin >> a[i];
        a[i] = muldiv(a[i]);
    }
    forDown(i, n, 1, -1){
        result += mp[a[i]];
        mp[a[i]]++;
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

// 