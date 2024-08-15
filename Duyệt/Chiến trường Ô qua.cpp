/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:29:05 - 15/08/2024

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

const int N             = 3e4 + 4;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int BLOCK_SIZE    = sqrt(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int t, n, a[N], l[N], r[N];
stack<int> st;

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
            l[i] = 0;
            r[i] = n + 1;
        }

        while (!st.empty()) st.pop();
            forUp(i, 1, n, 1) {
            while (!st.empty() && a[st.top()] >= a[i]) st.pop();
            if (!st.empty()) l[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();
        forDown(i, n, 1, -1) {
            while (!st.empty() && a[st.top()] >= a[i]) st.pop();
            if (!st.empty()) r[i] = st.top();
            st.push(i);
        }
        
        int result = -INF, u, v;
        forUp(i, 1, n, 1) {
            if (a[i] * (r[i] - l[i] - 1) > result) {
                result = a[i] * (r[i] - l[i] - 1);
                u = l[i] + 1;
                v = r[i] - 1;
            }
        }
        cout << result << " " << u << " " << v << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/kagain