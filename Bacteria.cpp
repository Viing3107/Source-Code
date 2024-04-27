// code by viing3107
#pragma GCC optimize("O2", "O3", "Ofast")
#pragma target("avx", "avx2", "fma")
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

const int N   = 1e2 + 2;
const int LIM = 9e5 + 5;

int n, m, a[N][N], min_value, b[N][N];

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
    forUp(i, 2, n - 1, 1){
        forUp(j, 2, m - 1, 1){
            min_value = min({a[i - 1][j], a[i][j - 1], a[i][j + 1], a[i + 1][j]});
            if (min_value){
                b[i][j] = min_value;
                a[i - 1][j] -= min_value;
                a[i][j - 1] -= min_value;
                a[i][j + 1] -= min_value;
                a[i + 1][j] -= min_value;    
            }
        }
    }

    forUp(i, 1, n, 1){
        forUp(j, 1, m, 1) cout << b[i][j] << " ";
        cout << endl;
    }

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bedao_g15_a