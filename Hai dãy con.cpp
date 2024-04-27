// code by viing3107
#pragma GCC optimize("O2", "O3", "Ofast")
#pragma target("avx", "avx2", "fma")
#include <bits/stdc++.h>
#define int long long
#define task "test"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define forEach(it, v) for(typeof v.begin() it = v.begin(), _e = v.end(); it != _e; it++)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

const int N = 1e6 + 6;

int n, k, a[N], prefixSum[N], kPre[N], kSuf[N], maxSuf[N], minSuf[N], res = -1e18;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> k;
    forUp(i, 1, n, 1){
        cin >> a[i];
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }
    // kPre[i] : tổng đoạn k liên tiếp bắt đầu từ i
    forUp(i, 1, n - k + 1, 1) kPre[i] = prefixSum[i + k - 1] - prefixSum[i - 1];
    // kPre[i] : tổng đoạn k liên tiếp kết thúc tại i
    forDown(i, n, k, -1) kSuf[i] = prefixSum[i] - prefixSum[i - k];
    // maxSuf[i] : tổng có độ dài k lớn nhất bắt đầu từ i -> n
    forDown(i, n - k + 1, k + 1, -1) maxSuf[i] = max(maxSuf[i + 1], kPre[i]);
    // minSuf[i] : tổng có độ dài k nhỏ nhất bắt đầu từ i -> n
    minSuf[n - k + 2] = 1e18;
    forDown(i, n - k + 1, k + 1, -1) minSuf[i] = min(minSuf[i + 1], kPre[i]);
    forUp(i, k, n - k, 1) res = max({res, abs(kSuf[i] - minSuf[i + 1]), abs(maxSuf[i + 1] - kSuf[i])});

    cout << res;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << ".\n";

	return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/bedao_r18_b