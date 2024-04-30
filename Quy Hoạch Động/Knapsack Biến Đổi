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
const int maxV = 1e3 + 3;

int N, W, v[maxN], w[maxN], dp[maxN][maxN * maxV], answer;
/*
    Thông thường :
        Mảng dp sẽ được khai báo là dp[N][W] = V
        dp[i][j] có ý nghĩa là giá trị lớn nhất khi xét đến đồ vật thứ i và túi chỉ đựng được khối lượng tối đa là j
    Tuy nhiên, trong bài này W quá lớn (1 <= W <= 1e9) có thể dẫn đến MLE và TLE, hơn nữa nhận thấy tổng giá trị các đồ vật khá nhỏ (khoảng 1e6) nên ta đổi lại như sau
        Mảng dp sẽ được khai báo là dp[N][V] = W
        dp[i][j] có ý nghĩa là khối lượng nhỏ nhất khi xét đến đồ vật thứ i và tổng giá trị các đồ vật là j 

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
    memset(dp, 0x3f, sizeof dp);
    // Truòng hợp cơ sở : Khi không chọn đồ vật nào thì giá trị và khối lượng đều là 0
    dp[0][0] = 0;
    forUp(i, 1, N, 1){
        forUp(j, 0, i * 1e3, 1){
            // không lựa chọn đồ vật i
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            // lựa chọn đồ vật i
            dp[i][j + v[i]] = min(dp[i][j + v[i]], dp[i - 1][j] + w[i]);
        }
    }
    forDown(j, N * 1e3, 0, -1){ // for tổng giá trị từ cao về thấp
        if (dp[N][j] <= W){ // nếu khối lượng tạo thành từ N món đồ vừa đủ nhỏ hơn W thì j là đáp án
            cout << j;
            return (0 ^ 0);
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

// https://oj.vnoi.info/problem/atcoder_dp_e
