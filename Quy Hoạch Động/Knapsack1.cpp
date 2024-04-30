// code by viing3107
#pragma GCC optimize("O2", "O3", "Ofast")
#pragma target("avx", "avx2", "fma")
#include <bits/stdc++.h>
#define int long long
#define task "test"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

const int maxN = 1e2 + 2;
const int maxW = 1e5 + 5;

int N, W, w[maxN], v[maxN], dp[maxN][maxW];

/*

    dp[i][j] có ỹ nghĩa là giá trị lớn nhất khi xét đến đồ vật thứ i và túi chỉ chứa được khối lượng tối đa là j

*/

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> N >> W;
    forUp(i, 1, N, 1) cin >> w[i] >> v[i];
    forUp(i, 1, N, 1){
        forUp(j, 1, W, 1){
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    cout << dp[N][W];

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/atcoder_dp_d
