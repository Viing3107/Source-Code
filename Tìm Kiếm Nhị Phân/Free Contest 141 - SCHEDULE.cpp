/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:15:29 - 09/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for(int i = (l); i >= (r); i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define endl                    "\n"

using namespace std;

const int N     = 1e6 + 6;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, result;
pair<int, int> a[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    forUp (i, 1, n, 1) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1, [&] (pair<int, int> u, pair<int, int> v) {
        return (u.first == v.first) ? u.second < v.second : u.first < v.first;
    });
    forUp (i, 1, n - 1, 1) {
        int l = i + 1, r = n, cnt = 0;
        while (r - l >= 0) {
            int m = l + r >> 1;
            if (a[m].first < a[i].second) {
                cnt = m - i;
                l = m + 1;
            }
            else r = m - 1;
        }
        result += cnt;
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

// https://oj.vnoi.info/problem/fc141_schedule