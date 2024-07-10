/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 00:01:10 - 11/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define endl                    "\n"

using namespace std;

const int N             = 3e4 + 4;
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, p, cnt[N][2], result = INF;
vector<int> prime, lpf;

void sieve(int n) {
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);
    forUp(x, 3, n, 2) {
        if (lpf[x] == 2) prime.push_back(lpf[x] = x);
        for (int i = 0; prime[i] <= lpf[x] && prime[i] * x <= n; i++)
            lpf[prime[i] * x] = prime[i];
    }
    lpf[1] = 1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> p;
    sieve(N);
    forUp(i, 1, n, 1) {
        int tmp = i;
        for (int y = lpf[tmp]; tmp != 1; y = lpf[tmp]) for (; tmp % y == 0; tmp /= y) cnt[y][0]++;
    }
    for (int y = lpf[p]; p != 1; y = lpf[p]) for (; p % y == 0; p /= y) cnt[y][1]++;
    forUp(i, 1, 30000, 1) {
        if (cnt[i][1]) result = min(result, cnt[i][0] / cnt[i][1]);
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

// https://oj.vnoi.info/problem/maxnum