/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 18:11:38 - 08/10/2024

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
#define forEach(it, v)          for (typeof v.begin() it = v.begin(), _e = it.end(); it != _e; it++)

using namespace std;

const int       N           = 1e5 + 5;
const int       MOD         = 1e9 + 7;
const int       LOG         = __lg(N) + 5;
const int       BLOCK_SIZE  = sqrt(N) + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

/*
    sum[l..r] % 3 = d
    <=> (sufSum[r] - sufSum[l - 1] + 3) % 3 = d

*/

string s;
int n, sufSum[N];
map<int, int> mp;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> s;
    n = SZ(s);
    s = " " + s;
    forDown(i, n, 1, -1) sufSum[i] = (sufSum[i + 1] + (s[i] - '0')) % 3;
    // forUp(i, 1, n, 1) cout << sufSum[i] << " \n"[i == n];
    int res = 0, d = sufSum[1];
    mp[0]++;
    forDown(i, n, 1, -1) {
        res += mp[(sufSum[i] - d + 3) % 3];
        mp[sufSum[i]]++;
    }
    // cout << mp[0] << " " << mp[1] << " " << mp[2] << endl;
    cout << res + (!d) - 1;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/th_thpt_20_c