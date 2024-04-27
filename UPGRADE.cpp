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

const int N   = 1e6 + 6;
const int LIM = 9e5 + 5;

int n, k, a[N], cnt, res;
priority_queue<int, vector<int>, greater<int>> Q;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> k;
    forUp(i, 1, n, 1){
        cin >> a[i];
        Q.push(a[i]);
    }
    while (!Q.empty()){
        int top = Q.top();
        Q.pop();
        int cnt = 1;
        while (!Q.empty() && Q.top() == top && cnt < k){
            cnt++;
            Q.pop();
        }
        if (cnt == k) Q.push(top + 1);
        else res += cnt;
    }
    cout << res;

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcc2022q2_upgrade