/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 00:59:09 - 28/06/2024

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

int n, t, m, dp[N];
pair<int, int> a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> t >> m;
    forUp(i, 1, m, 1) cin >> a[i].first >> a[i].second;
    dp[1] = a[1].second;
    forUp(i, 2, m, 1){
        dp[i] = dp[i - 1];
        int tmp = 0;
        forUp(j, 1, i - 1, 1){
            if (a[i].first == a[j].first) tmp = max(tmp, a[j].second);
        }
        dp[i] = max(dp[i], dp[i] + a[i].second - tmp);
    }
    forUp(i, 1, m, 1){
        if (dp[i] >= t){
            cout << i;
            return (0 ^ 0);
        }
    }
    cout << -1;

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb041_selling