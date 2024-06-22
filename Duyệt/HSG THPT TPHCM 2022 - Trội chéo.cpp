/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 14:45:43 - 02/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e3 + 3;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, a[N][N], preSum[N], cnt;
bool check3, res;

bool check(){
    forUp(i, 1, n, 1){
        if (a[i][i] < preSum[i]) return false;
        if (a[i][i] > preSum[i]){
            check3 = true;
            cnt++;
        }
    }
    return check3;
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
    forUp(i, 1, n, 1){
        forUp(j, 1, n, 1){
            cin >> a[i][j];
            if (i == j) continue;
            preSum[i] += a[i][j];
        }
    }
    if (check()) cout << "YES" << endl << cnt;
    else cout << "NO";
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/hcm_thpt_22_a