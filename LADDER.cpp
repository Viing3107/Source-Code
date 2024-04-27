// code by viing3107
#pragma GCC                     optimize("O2", "O3", "Ofast")
#pragma                         target("avx", "avx2", "fma")
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define gcd(a, b)               __gcd(a, b)
#define lcm(a, b)               a / gcd(a, b) * b

using namespace std;

const int N = 1e5 + 5;

int n, m, a[N], l, r;

int Down(int l, int r){
    forUp(i, l + 1, r, 1){
        if (a[i] - a[i - 1] > 0) return false;
    }
    return true;
}

bool Up(int l, int r){
    forUp(i, l + 1, r, 1){
        if (a[i] - a[i - 1] < 0) return Down(i - 1, r);
    }
    return true;
}

bool check(int l, int r){
    return Up(l, r);
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
    forUp(i, 1, n, 1) cin >> a[i];
    while (m--){
        cin >> l >> r;
        cout << (check(l, r) ? "Yes\n" : "No\n");
    }

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fct034_ladder