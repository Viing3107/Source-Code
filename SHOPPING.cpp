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

int A, B, M, a[N], b[N], answer = INF, x, y, z;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> A >> B >> M;
    forUp(i, 1, A, 1) cin >> a[i];
    forUp(i, 1, B, 1) cin >> b[i];
    answer = min(answer, *min_element(a + 1, a + A + 1) + *min_element(b + 1, b + B + 1));
    forUp(i, 1, M, 1){
        cin >> x >> y >> z;
        answer = min(answer, a[x] + b[y] - z);
    }
    cout << answer;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc112_shopping
