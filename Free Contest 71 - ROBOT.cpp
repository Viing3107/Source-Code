// code by viing3107
#pragma GCC optimize("O2", "O3", "Ofast")
#pragma target("avx", "avx2", "fma")
#include <bits/stdc++.h>
#define int long long
#define task "test"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

const int N = 1e5 + 5;

int n, m, k, l, r, first, second, moveCommand, position, length, answer;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m >> k;
    forUp(i, 1, m, 1){
        cin >> moveCommand;
        if (moveCommand == 1){
            position--;
            l = min(l, position);
        }
        else{
            position++;
            r = max(r, position);
        }
    }
    length = r - l + 1;
    forUp(i, 1, k, 1){
        cin >> second;
        if (second - first - 1 >= length) answer += second - first - length;
        first = second;
    }
    second = n + 1;
    if (second - first - 1 >= length) answer += second - first - length;
    cout << answer;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc071_robot
