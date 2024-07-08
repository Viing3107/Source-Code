/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 13:39:07 - 08/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e6 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, q, cnt[N][30];
string s;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> q;
    cin >> s;
    forUp (i, 0, n - 1, 1) {
        if (i) forUp (j, 1, 26, 1) cnt[i][j] = cnt[i - 1][j];
        cnt[i][s[i] - 'a' + 1]++;
    }
    while (q--) {
        int maximum = 0, check = 0, l, r, result = 0;
        cin >> l >> r;
        vector<int> v;
        forUp (i, 1, 26, 1) {
            int x = cnt[r][i] - cnt[l - 1][i];
            if (x % 2) v.push_back(x);
        }
        if (v.size() <= 1) cout << 0 << "\n";
        else {
            result = v.size();
            cout << (result - result % 2) / 2 << "\n";
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

// https://oj.vnoi.info/problem/olp_kc23_beastr