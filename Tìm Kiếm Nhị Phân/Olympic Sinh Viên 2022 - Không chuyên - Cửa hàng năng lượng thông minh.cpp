/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:48:39 - 10/07/2024

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

const int N     = 5e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, a[N], q, l, r, tmp;
vector<int> exponential, v;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    for (int i = 1; i <= 30; i++) exponential.push_back(1ll << i);
    for (int i = 1; i <= 19; i++) exponential.push_back(pow(3, i));
    for (int i = 1; i <= 13; i++) exponential.push_back(pow(5, i));
    sort(exponential.begin(), exponential.end());

    cin >> n >> q;
    forUp(i, 1, n, 1) {
        cin >> a[i];
        if (binary_search(exponential.begin(), exponential.end(), a[i]) || a[i] == 1) v.push_back(a[i]);
    }
    sort(v.begin(), v.end());

    while (q--) {
        cin >> l >> r;
        l = lower_bound(v.begin(), v.end(), l) - v.begin();
        r = upper_bound(v.begin(), v.end(), r) - v.begin() - 1;
        cout << r - l + 1 << endl;
    }

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/olp_kc22_smartshop