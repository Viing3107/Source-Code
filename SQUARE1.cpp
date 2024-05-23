/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 15:04:43 - 23/05/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)

using namespace std;

const int N     = 2e2 + 2;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, m, a[N][N], preSum[N][N], row[N][N], result;

int get(int x, int y, int z, int t){
    return preSum[z][t] - preSum[z][y - 1] - preSum[x - 1][t] + preSum[x - 1][y - 1];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    cin >> n >> m;
    forUp(i, 1, n, 1) forUp(j, 1, m, 1) cin >> a[i][j];
    forUp(i, 1, n, 1) forUp(j, 1, m, 1) row[i][j] = row[i][j - 1] + a[i][j];
    forUp(i, 1, n, 1) forUp(j, 1, m, 1) preSum[i][j] = preSum[i - 1][j] + row[i][j];
    forUp(i, 1, n, 1){
        forUp(j, 1, m, 1){
            forUp(length, 1, min(n, m), 1){
                if (i + length - 1 > n || j + length - 1 > m) break;
                if (
                    get(i, j, i, j + length - 1) == length &&
                    get(i, j, i + length - 1, j) == length &&
                    get(i, j + length - 1, i + length - 1, j + length - 1) == length &&
                    get(i + length - 1, j, i + length - 1, j + length - 1) == length
                ) result = max(result, length * length);
            }
        }
    }
    cout << result;

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc104_square1