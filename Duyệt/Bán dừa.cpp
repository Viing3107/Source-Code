/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 20:55:26 - 15/08/2024

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
const int BLOCK_SIZE    = sqrt(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, a[N], l[N], r[N];
stack<int> st;

/*

ý tưởng: 
    với mỗi i, kiểm tra xem có tồn tại hình vuông với cạnh là a[i] không
    gọi l[i] là vị trí j thỏa mãn
        j < i
        a[j] < a[i]
        j gần i nhất

    gọi r[i] là vị trí j thỏa mãn
        j > i
        a[j] < a[i]
        j gần i nhất

    nếu r[i] - l[i] - 1 < a[i] thì không tồn tại hình vuông với cạnh là a[i]

*/

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
    forUp(i, 1, n, 1) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (!st.empty()) l[i] = st.top();
        st.push(i);
    }
    // forUp(i, 1, n, 1) cout << l[i] << " ";
    // cout << endl;
    forUp(i, 1, n, 1) r[i] = n + 1;
    while (!st.empty()) st.pop();
    forDown(i, n, 1, -1) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (!st.empty()) r[i] = st.top();
        st.push(i);
    }
    // forUp(i, 1, n, 1) cout << r[i] << " ";
    // cout << endl;
    int result = 0;
    forUp(i, 1, n, 1) if (r[i] - l[i] - 1 >= a[i]) result = max(result, a[i]);
    cout << result;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/kplank