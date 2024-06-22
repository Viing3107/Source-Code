/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 08:31:50 - 22/06/2024

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

int n, m, a[N][N], mark[N][N], result;

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
    
    forUp(i, 1, n, 1){
        mark[i][max_element(a[i] + 1, a[i] + m + 1) - a[i]] = true;
    }
    forUp(j, 1, m, 1){
        pair<int, int> maximum;
        int m = -1;
        forUp(i, 1, n, 1){
            if (a[i][j] > m){
                m = a[i][j];
                maximum = {i, j};
            }
        }
        mark[maximum.first][maximum.second] = true;
    }
    forUp(i, 1, n, 1) forUp(j, 1, m, 1) result += (!mark[i][j] ? a[i][j] : 0);
    cout << result;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc062_delbox
