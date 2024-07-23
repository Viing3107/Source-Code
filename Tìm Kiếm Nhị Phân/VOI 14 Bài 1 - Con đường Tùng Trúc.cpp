/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 16:19:58 - 23/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 3e5 + 5;
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, a, b, minLength = INF;

struct tree{
    int dist, type;

    friend bool operator < (tree u, tree v) {
        return (u.dist < v.dist);
    }
} t[N];

pair<int, int> cnt[N];

int f(int l, int r) {
    return ((cnt[r].first - cnt[l - 1].first >= a) && (cnt[r].second - cnt[l - 1].second) >= b);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> a >> b;
    forUp(i, 1, n, 1) cin >> t[i].dist >> t[i].type;
    sort(t + 1, t + n + 1);
    forUp(i, 1, n, 1) {
        cnt[i] = cnt[i - 1];
        if (t[i].type == 1) cnt[i].first++;
        else cnt[i].second++;
    }
    forUp(i, 1, n - 2, 1) {
        int l = i + 2, r = n, pos = 0;
        while (r - l >= 0) {
            int m = l + r >> 1;
            if (f(i, m)) {
                pos = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        if (pos) minLength = min(minLength, t[pos].dist - t[i].dist);
    }
    cout << (minLength == INF ? -1 : minLength);

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/minroad