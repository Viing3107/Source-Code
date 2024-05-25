/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 20:17:48 - 25/05/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, k, a[N], preSum[N], result;

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
        a[i] %= 2;
        preSum[i] = preSum[i - 1] + a[i];
    }
    forUp(i, 1, n, 1){
        int l = i, r = n, ansL = 0, ansR = 0;
        while (r - l >= 0){
            int m = l + r >> 1;
            if (preSum[m] - preSum[i - 1] >= k){
                ansL = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        l = i, r = n;
        while (r - l >= 0){
            int m = l + r >> 1;
            if (preSum[m] - preSum[i - 1] <= k){
                ansR = m;
                l = m + 1;
            }
            else r = m - 1;
        }
        if (ansL && ansR) result += ansR - ansL + 1;
    }
    cout << result;

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb025_koddflo