/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:52:02 - 03/08/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define SZ(v)                   (int) v.size()
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e5 + 5;
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int t, n, a[N];
vector<int> pos[N];

bool check(int x, int length) {
    if (!SZ(pos[x])) return false;
    forUp(i, 1, SZ(pos[x]) - 1, 1) {
        if (pos[x][i] - pos[x][i - 1] > length) return false;
    }
    return pos[x][0] <= length && pos[x].back() > n - length;
}

void solve(int length) {
    forUp(i, 1, n, 1) {
        if (check(i, length)) {
            cout << i << " ";
            return;
        }
    }
    cout << -1 << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> t;
    while (t--) {
        cin >> n;
        forUp(i, 1, n, 1) {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }
        forUp(i, 1, n, 1) solve(i);
        cout << endl;
        forUp(i, 1, n, 1) pos[i].clear();
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc126_knumber