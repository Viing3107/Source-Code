/*
	Author : Do Quang Vinh
	Kim Son A High School - Ninh Binh
	Created : 11:51:37 - 31/05/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, a[N], dp[N], result;

/*
	gọi dp[i] là dãy con có độ dài i và có phần tử kết thúc là dp[i]
	khi xét đến a[i], ta cần tìm dãy con có độ dài là x (tìm dp[x]) sao cho dp[x] <= a[i] và x phải lớn nhất
	để làm được điều này, có thể dễ dàng chặt nhị phân để tìm x trong O(log(n))
	đáp án sẽ là dãy con có độ dài lớn nhất
*/

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

	cin >> n;
	forUp(i, 1, n, 1) cin >> a[i];
	dp[1] = a[1];
	forUp(i, 1, n, 1){
		int idx = lower_bound(dp + 1, dp + result + 1, a[i]) - dp - 1;
		dp[idx + 1] = a[i];
		result = max(result, idx + 1);
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

// https://oj.vnoi.info/problem/lis
