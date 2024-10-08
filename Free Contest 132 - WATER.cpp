/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 13:09:53 - 10/08/2024

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

const int N             = 1e6 + 6;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, a[N], r[N], l[N], preSum[N], result;

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
    forUp(i, 1, n, 1) l[i] = max({l[i - 1], a[i - 1], a[i]});
    forDown(i, n, 1, -1) r[i] = max({r[i + 1], a[i + 1], a[i]});
    forUp(i, 1, n, 1) result += min(l[i], r[i]) - a[i];
    stack<int> st;
    forUp(i, 1, n, 1) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        if (!st.empty()) l[i] = st.top();
        else l[i] = 0;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    forDown(i, n, 1, -1) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        if (!st.empty()) r[i] = st.top();
        else r[i] = 0;
        st.push(i);
    }
    // forUp(i, 1, n, 1) cout << l[i] << " ";
    // cout << endl;
    // forUp(i, 1, n, 1) cout << r[i] << " ";
    // cout << endl;
    int maxVal = 0;
    forUp(i, 1, n, 1) {
        if (l[i] && !r[i]) maxVal = max(maxVal, i - l[i] - 1);
        else if (!l[i] && r[i]) maxVal = max(maxVal, r[i] - i - 1);
    }
    cout << result + maxVal;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc132_water