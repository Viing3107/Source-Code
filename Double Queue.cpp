/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:35:31 - 05/08/2024

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

set<pair<int, int>> s;
int type, k, p;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    while (cin >> type) {
        if (!type) break;
        else if (type == 1) {
            cin >> k >> p;
            s.insert({p, k});
        }
        else if (type == 2) {
            if (s.empty()) cout << 0 << endl;
            else {
                auto it = --s.end();
                cout << (*it).second << endl;
                s.erase(it);
            }
        }
        else {
            if (s.empty()) cout << 0 << endl;
            else {
                cout << (*s.begin()).second << endl;
                s.erase(s.begin());
            }
        }
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/mse07b