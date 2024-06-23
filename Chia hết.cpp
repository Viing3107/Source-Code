/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 20:56:12 - 23/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e6 + 6;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, a[N], q, x, p;
vector<int> prime, lpf;
map<int, int> mul, mp;

void sieve(int n){
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);
    forUp(x, 3, n, 2){
        if (lpf[x] == 2) prime.push_back(lpf[x] = x);
        for (int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; i++)
            lpf[prime[i] * x] = prime[i];
    }
}

int solve(map<int, int> &mp, int &x){
    for (auto it : mp){
        if (mul[it.first] < it.second * x) return false;
    }
    return true;
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
    cin >> n;
    forUp(i, 1, n, 1){
        cin >> a[i];
        for (int y = lpf[a[i]]; a[i] != 1; y = lpf[a[i]]){
            for (; a[i] % y == 0 && a[i] != 1; a[i] /= y) mul[y]++;
        }
    }
    cin >> q;
    while (q--){
        cin >> x >> p;
        map<int, int> mp;
        for (int y = lpf[x]; x != 1; y = lpf[x]){
            for (; x % y == 0 && x != 1; x /= y) mp[y]++;
        }
        cout << solve(mp, p);
    }

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/codetour24_c2_e