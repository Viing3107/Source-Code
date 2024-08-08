/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 23:05:43 - 08/08/2024

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

const int N             = 1e5 + 5;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int q, n, a[N], cnt[N];

string check() {
    int minDepth;
    forUp(i, 1, 1e5, 1) {
        if (cnt[i]) {
            minDepth = i;
            break;
        }
    }
    forDown(i, 1e5, minDepth, -1) {
        if (cnt[i] & 1) return "NO\n";
        cnt[i - 1] += cnt[i] >> 1;
    }
    return ((cnt[minDepth] >> minDepth) == 1 ? "YES\n" : "NO\n");
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> q;
    while (q--) {
        memset(cnt, 0, sizeof cnt);
        cin >> n;
        forUp(i, 1, n, 1) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        cout << check();
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bedao_r02_leaves