// code by viing3107
#pragma GCC optimize("O2", "O3", "Ofast")
#pragma target("avx", "avx2", "fma")
#include <bits/stdc++.h>
#define int long long
#define task "test"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define forEach(it, v) for(typeof v.begin() it = v.begin(), _e = v.end(); it != _e; it++)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

const int N = 1e5 + 5;

int n, q, a[N], x, l, r, m, res, ind;
map<int, int> mp;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> q;
    forUp(i, 1, n, 1) cin >> a[i];
    while (q--){
        cin >> x;
        if (mp.count(x)) cout << mp[x] << endl;
        else{
            l = 0;
            r = 3e18;
            while (r - l >= 0){
                m = l + r >> 1;
                ind = lower_bound(a + 1, a + n + 1, m) - a - 1;
                if (m - ind <= x){
                    l = m + 1;
                    res = m;
                }
                else r = m - 1;
            }
            mp[x] = res;
            cout << res << endl;
        }
    }

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc137_ksex