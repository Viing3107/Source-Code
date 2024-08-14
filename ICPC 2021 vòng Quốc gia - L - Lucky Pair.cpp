/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 19:43:37 - 14/08/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define SZ(v)                   (int) v.size()
#define all(v)                  v.begin(), v.end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 3e5 + 5;
const int MAX_ELEMENT   = 1e7 + 7;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int BLOCK_SIZE    = sqrt(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, a[N], fact[MAX_ELEMENT], result;
vector<int> prime, lpf;

void sieve(int n) {
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);
    forUp(x, 3, n, 2) {
        if (lpf[x] == 2) prime.push_back(lpf[x] = x);
        for (int i = 0; prime[i] <= lpf[x] && prime[i] * x <= n; i++) lpf[prime[i] * x] = prime[i];
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    sieve(MAX_ELEMENT);
    cin >> n;
    forUp(i, 1, n, 1) cin >> a[i];
    forDown(i, n, 1, -1) {
        int val = a[i], mul = 1;
        for (int y = lpf[val]; val != 1; y = lpf[val]) {
            mul *= y;
            while (val % y == 0) val /= y;
        }
        result += fact[mul];
        fact[mul]++;
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

// https://oj.vnoi.info/problem/icpc21_national_l