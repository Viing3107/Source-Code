/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)

using namespace std;

const int N     = 1e6 + 6;
const int LIM   = 78497;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, a[N], prefixSum[N], minPrefix[N], answer = -INF;
vector<int> prime, lpf, ind;

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
    
    sieve(1e6);
    cin >> n;
    forUp(i, 1, n, 1){
        cin >> a[i];
        prefixSum[i] = prefixSum[i - 1] + a[i];
        if (isPrime(i)) ind.push_back(i - 1);
    }
    minPrefix[1] = prefixSum[1];
    forUp(i, 1, ind.size() - 1, 1) minPrefix[ind[i]] = min(minPrefix[ind[i - 1]], prefixSum[ind[i]]);
    forUp(i, 1, ind.size() - 1, 1){
        answer = max(answer, prefixSum[ind[i] + 1] - minPrefix[ind[i]]);
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
