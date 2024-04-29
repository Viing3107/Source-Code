// code by viing3107
#pragma GCC optimize("O2", "O3", "Ofast")
#pragma target("avx", "avx2", "fma")
#include <bits/stdc++.h>
#define int long long
#define double long double
#define task "test"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

const int N = 1e5 + 5;
const int LIM = 1e6 + 6;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n, F0, d, F1, F2, mark[N], dist;
pair<int, int> a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> F0 >> d;
    forUp(i, 1, n, 1){
        mark[i] = -1;
        cin >> a[i].first >> a[i].second;
        if (i == F0) mark[i] = 0;
    }
    d *= d;
    forUp(i, 1, n, 1){
        if (!mark[i]) continue;
        dist = abs(a[F0].first - a[i].first) * abs(a[F0].first - a[i].first) + abs(a[F0].second - a[i].second) * abs(a[F0].second - a[i].second);
        if (dist < d) mark[i] = 1;
    }
    forUp(i, 1, n, 1){
        if (mark[i] == 1){
            forUp(j, 1, n, 1){
                if (!mark[j] || mark[j] == 1) continue;
                dist = abs(a[i].first - a[j].first) * abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second) * abs(a[i].second - a[j].second);
                if (dist < d) mark[j] = 2;
            }
        }
    }
    forUp(i, 1, n, 1){
        F1 += mark[i] == 1;
        F2 += mark[i] == 2;
    }
    cout << F1 << " " << F2;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/olp_ct21_detectf12
