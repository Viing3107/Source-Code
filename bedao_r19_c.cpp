// code by viing3107
#include <bits/stdc++.h>
#define int long long
#define double long double
#define task "test"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define forEach(it, v) for(typeof v.begin() it = v.begin(), _e = v.end(); it != _e; it++)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

const int N   = 1e6 + 6;
const int LIM = 9e5 + 5;
const int MOD = 1e3 + 7;

int n, a[N], dp[N];
// dp[i] : dãy con dài nhất khi kết thúc tại giá trị i

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
    int j = 0;
	forUp(i, 1, n, 1){
		dp[a[i]] = dp[a[i] + 1] + 1;
		if (dp[a[j]] < dp[a[i]]) j = i;
	}
    forUp(i, 1, n, 1) cout << dp[i] << " ";
    cout << endl;
	cout << dp[a[j]] << endl;
	forUp(i, 1, n, 1){
		if (a[i] == a[j] + dp[a[j]] - 1){
			cout << i << ' ';
			dp[a[j]]--;
		}
	}

    return (0 ^ 0);
}

/*
    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bedao_r19_c
