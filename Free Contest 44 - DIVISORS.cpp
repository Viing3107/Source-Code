/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 14:43:29 - 28/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 450;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, k, result, cnt[N][N];
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

// C(k, n) = n! / (k! * (n - k)!)

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    sieve(N);
    forUp(i, 1, 431, 1){
        // đếm tập ước của i
        int tmp = i;
        for (int y = lpf[tmp]; tmp != 1; y = lpf[tmp]){
            cnt[i][y]++;
            tmp /= y;
        }
    }
    forUp(i, 2, 431, 1){
        forUp(j, 1, 431, 1) cnt[i][j] += cnt[i - 1][j];
    }
    while (cin >> n >> k){
        result = 1;
        forUp(i, 1, 431, 1) result *= cnt[n][i] - cnt[k][i] - cnt[n - k][i] + 1;
        cout << result << "\n";
    }
    
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc044_divisors