/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:24:59 - 24/07/2025

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define BIT(i, n)               ((n) >> (i) & 1)
#define SZ(v)                   (int) (v).size()
#define ALL(v)                  (v).begin(), (v).end()
#define LOG(x)                  (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof (v).begin() it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int       BASE        = 311;
const int       BLOCK_SIZE  = 320;
const int       N           = 5e5 + 5;
const int       VAL         = 5e5 + 6;
const int       MOD         = 1e9 + 7;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, a[N], cnt[VAL];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    forUp(i, 1, n, 1) cin >> a[i];
    int res = 0;
    int l = 1, r = 1;
    while (l <= r && r <= n) {
        int val = 0;
        for (; r <= n; r++) {
            cnt[a[r]]++;
            if (cnt[a[r]] > 2) {
                val = a[r];
                break;
            }
            res += r - l + 1;
        }
        if (val) { // thoát khỏi vòng for do cnt[val] > 2
            while (l <= r && cnt[val] > 2) {
                cnt[a[l]]--;
                l++;
            }
            res += r - l + 1;
        }
        // cout << l << " " << r << " " << res << endl;
        r++;
    }
    cout << res;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/fc100_beautarr