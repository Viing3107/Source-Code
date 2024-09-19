#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N     = 1e5 + 5;

int n, k, a[N];

bool check(){
    int g = 0;
    for (int i = 2; i <= n; i++) g = __gcd(g, a[i] - a[i - 1]);
    if (g % k) return false;
    return true;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    if (!check()) cout << -1;
    else {
        int res = 0;
        for (int i = 1; i <= n; i++) res += (a[i] - a[1]) / k;
        cout << res;
    }
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/c11pines
