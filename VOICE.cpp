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

const int N = 1e3 + 3;

int n, cnt, a[N], answer;

void Down(int i){
    cnt++;
    forUp(j, i + 1, n, 1){
        if (a[j] <= a[j - 1]) cnt++;
        else return;
    }
}

void Up(int i){
    cnt = 1;
    forUp(j, i + 1, n, 1){
        if (a[j] >= a[j - 1]) cnt++;
        else{
            Down(j);
            return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    forUp(i, 1, n, 1) cin >> a[i];
    forUp(i, 1, n, 1){
        Up(i);
        answer = max(answer, cnt);
    }
    cout << answer;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb044_voice
