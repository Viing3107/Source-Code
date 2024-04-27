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

const int N = 1e5 + 5;

int t, n, a[N], i, mark[N];

void process(){
    mark[a[1]] = 1;
    forUp(i, 2, n, 1){
        if (!mark[a[i]]) mark[a[i]] = i; // lưu vị trí đầu tiên mà a[i] xuất hiện trong mảng
        else if (mark[a[i]] <= i - 2){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> t;
    while (t--){
        cin >> n;
        forUp(i, 1, n, 1) cin >> a[i];
        forUp(i, 1, n, 1) mark[i] = 0;
        process();
    }

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb055_palinarray
