/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:42:46 - 04/08/2024

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
const int LOG           = __lg(N) + 5;
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, k, a[N], result;

/*

gọi f(x) là số dãy con khi chia dãy ban đầu sao cho tổng phần tử trong mỗi dãy con đều <= x
nhận xét: f(x) >= f(x + 1)

*/

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> k;
    forUp(i, 1, n, 1) cin >> a[i];
    int l = *min_element(a + 1, a + n + 1), r = 1e14;
    while (r - l >= 0) {
        int m = l + r >> 1;
        int maxVal = 0, s = 0, cnt = 1;
        forUp(i, 1, n, 1) {
            if (s + a[i] <= m) s += a[i];
            else {
                cnt++;
                maxVal = max(maxVal, s);
                s = a[i];
            }
        }
        maxVal = max(maxVal, s);
        if (cnt <= k) {
            result = maxVal;
            r = m - 1;
        }
        else l = m + 1;
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

// https://oj.vnoi.info/problem/fc136_splitting