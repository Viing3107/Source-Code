/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 18:51:49 - 05/10/2024

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
#define forEach(it, v)          for (typeof v.begin() it = v.begin(), _e = it.end(); it != _e; it++)

using namespace std;

const int N             = 1e5 + 5;
const int MOD           = 1e6 + 7;
const int LOG           = __lg(N) + 5;
const int BLOCK_SIZE    = sqrt(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, k, dp[N][2];

/*
    số lượng xâu nhị phân chứa k số 1 liên tiếp
    = 2^n - số lượng xâu nhị phân không tồn tại k số 1 liên tiếp
    gọi dp[i][j] là số lượng xâu nhị phân khi xét đến vị trí i, số cuối cùng là j
    
*/

int binPow(int n) { // calculate 2^n
    if (!n) return 1;
    int val = binPow(n >> 1);
    if (n & 1) return val * val * 2 % MOD;
    return val * val % MOD;
}

namespace subtask1 {
    void solve() {
        dp[1][0] = dp[1][1] = 1;
        forUp(i, 2, k - 1, 1) forUp(j, 0, 1, 1) dp[i][j] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        forUp(i, k, n, 1) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            forUp(j, i - k + 1, i - 1, 1) (dp[i][1] += dp[j][0]) %= MOD;
        }

        cout << ((binPow(n) - dp[n][0] - dp[n][1]) % MOD + MOD) % MOD;
    }
}

namespace subtask2 {
    int preSum[N];

    void solve() {
        if (k == 1) return void(cout << ((binPow(n) - 1) % MOD + MOD) % MOD);
        dp[1][0] = dp[1][1] = preSum[1] = 1;
        forUp(i, 2, k - 1, 1) {
            forUp(j, 0, 1, 1) dp[i][j] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            preSum[i] = (preSum[i - 1] + dp[i][0]) % MOD;
        }
        forUp(i, k, n, 1) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][1] = ((preSum[i - 1] - preSum[i - k]) % MOD + MOD) % MOD;
            preSum[i] = (preSum[i - 1] + dp[i][0]) % MOD;
        }

        cout << ((binPow(n) - dp[n][0] - dp[n][1]) % MOD + MOD) % MOD;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> k;
    if (n <= 1e3) subtask1::solve();
    else subtask2::solve();
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc009_bitstr