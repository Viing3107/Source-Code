/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 19:37:56 - 12/08/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define SZ(v)                   (int) v.size()
#define all(v)                  v.begin(), v.end()
#define lcm(x, y)               (x) / __gcd(x, y) * (y)
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e6;
const int MOD           = 1e9 + 7;
const int PRIME_SIZE    = 999999;
const int LOG           = __lg(N) + 5;
const int BLOCK_SIZE    = sqrt(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int t, a, b, mul[PRIME_SIZE], answer[N];
vector<int> prime, lpf;

void sieve(int n) {
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);
    forUp(x, 3, n, 2) {
        if (lpf[x] == 2) prime.push_back(lpf[x] = x);
        for (int i = 0; prime[i] <= lpf[x] && prime[i] * x <= n; i++) lpf[prime[i] * x] = prime[i];
    }
}

struct testcase {
    int l, r, id;

    friend bool operator < (const testcase &u, const testcase &v) {
        if (u.l / BLOCK_SIZE != v.l / BLOCK_SIZE) return u.l < v.l;
        if (u.l / BLOCK_SIZE & 1) return u.r < v.r;
        return u.r > v.r;
    }
} T[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    sieve(N);
    cin >> t;
    forUp(i, 1, t, 1) {
        cin >> T[i].l >> T[i].r;
        T[i].id = i;
    }
    sort(T + 1, T + t + 1);
    int l = 1, r = 0;
    forUp(i, 1, t, 1) {
        int u = T[i].l, v = T[i].r;
        while (l < u) {
            int n = l;
            for (int y = lpf[n]; n != 1; y = lpf[n]) for (; n % y == 0; n /= y) mul[y]--;
            l++;
        }
        while (l > u) {
            l--;
            int n = l;
            for (int y = lpf[n]; n != 1; y = lpf[n]) for (; n % y == 0; n /= y) mul[y]++;
        }
        while (r < v) {
            r++;
            int n = r;
            for (int y = lpf[n]; n != 1; y = lpf[n]) for (; n % y == 0; n /= y) mul[y]++;
        }
        while (r > v) {
            int n = r;
            for (int y = lpf[n]; n != 1; y = lpf[n]) for (; n % y == 0; n /= y) mul[y]--;
            r--;
        }
        int result = 1;
        forUp(i, 1, PRIME_SIZE - 1, 1) (result *= 2 * mul[i] + 1) %= MOD;
        answer[T[i].id] = result;
    }
    forUp(i, 1, t, 1) cout << answer[i] << endl;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fct027_5_lcm