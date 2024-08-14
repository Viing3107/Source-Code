/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 12:50:24 - 14/08/2024

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

const int N             = 5e4;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int BLOCK_SIZE    = sqrt(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, k;
vector<int> prime, lpf;
string s;

void sieve(int n) {
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);
    forUp(x, 3, n, 2) {
        if (lpf[x] == 2) prime.push_back(lpf[x] = x);
        for (int i = 0; prime[i] <= lpf[x] && prime[i] * x <= n; i++) lpf[prime[i] * x] = prime[i];
    }
}

void process() {
    forUp(i, 0, SZ(s) - 2, 1) if (s[i] < s[i + 1]) return void(s.erase(s.begin() + i));
    s.erase(s.end() - 1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    sieve(611960);
    cin >> n >> k;
    forUp(i, 0, n - 1, 1) s += to_string(prime[i]);
    for (int i = 0; i <= SZ(s) - 2 && k; i++) if (s[i] < s[i + 1]) {
        s.erase(s.begin() + i);
        k--;
        i = max(-1ll, i - 2);
    }
    forUp(i, 0, SZ(s) - k - 1, 1) cout << s[i];
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/kdel