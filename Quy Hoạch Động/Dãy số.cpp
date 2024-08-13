/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 12:14:05 - 13/08/2024

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

const int N             = 25e2 + 2;
const int MAX_ELEMENT   = 5e6 + 6;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int BLOCK_SIZE    = sqrt(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int t, n, a[N], dp[N][N], last[MAX_ELEMENT];

/*

gọi dp[i][j] (i < j) là dãy con có độ dài dài nhất có 2 giá trị cuối cùng là a[i] và a[j]

dp[i][j] = max(dp[i][j], dp[k][i] + 1) nếu 
	k < i
	a[k] + a[i] = a[j]

*/

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
        forUp(i, 1, n, 1) cin >> a[i];
        forUp(i, 1, n, 1) forUp(j, 1, n, 1) dp[i][j] = 2;
        memset(last, 0, sizeof last);
        int result = 0;
        forUp(i, 1, n - 1, 1) {
            forUp(j, i + 1, n, 1) {
                dp[i][j] = max(dp[i][j], dp[last[a[j] - a[i] + (int) 2e6]][i] + 1);
                result = max(result, dp[i][j]);
            }
            last[a[i] + (int) 2e6] = i;
        }
        cout << result << endl;
        // forUp(i, 1, n, 1) forUp(j, 1, n, 1) cout << dp[i][j] << " \n"[j == n];
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/thseq