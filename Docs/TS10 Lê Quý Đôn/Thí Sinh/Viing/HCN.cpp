/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 15:40:04 - 18/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "HCN"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e2 + 2;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, dp[N];

struct HCN{
    int x, y, x2, y2;
} a[N];

bool cmp(HCN u, HCN v){ // u có nằm trong v không ?
    return u.x >= v.x && u.x <= v.x2 && u.y2 >= v.y && u.y2 <= v.y2;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    forUp(i, 1, n, 1) cin >> a[i].x >> a[i].y >> a[i].x2 >> a[i].y2;
    sort(a + 1, a + n + 1, cmp);
    dp[1] = 1;
    forUp(i, 2, n, 1){
        dp[i] = dp[i - 1];
        forUp(j, 1, i - 1, 1){
            if (cmp(a[j], a[i])) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << dp[n];
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 