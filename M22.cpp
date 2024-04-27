#include                        <bits/stdc++.h>
#define int                     long long
#define task                    "test"
#define forUp(i, l, r, step)    for (int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for (int i = l; i >= r; i += step)


using namespace std;

const int N = 2e5 + 5;

int mark[N][25];  // mark[i][j] : số lượng các phần tử sau a[i] mà chia 23 dư j
// a[i] - a[j] đồng dư 0 (modulo 23) --> a[i] đồng dư a[j] (modulo 23)

int n, res, ind, a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forUp(i, 1, n, 1){
        cin >> a[i];
        a[i] %= 23;
    }
    forDown(i, n, 1, -1){
        forUp(j, 0, 22, 1) mark[i][j] = mark[i + 1][j];
        mark[i][a[i]]++;
    }

    forUp(i, 1, n - 6, 1){
        ind = i + 6;
        while (ind <= n && a[ind] != a[i]) ind++;
        res += mark[ind][a[i]];
    }
    cout << res;

    return (0 ^ 0);
}

/*

    /\_/\
   ( =._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bedao_m22_b