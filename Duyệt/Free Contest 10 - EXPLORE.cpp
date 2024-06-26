/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 23:23:13 - 26/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, t, a[N], result, timer;

bool cmp(int u, int v){
    return abs(u) < abs(v);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> t >> n;
    forUp(i, 1, n, 1) cin >> a[i];
    sort(a + 1, a + n + 1, cmp);
    forUp(i, 1, n, 1){
        if (timer + abs(a[i] - a[i - 1]) > t) break;
        result++;
        timer += abs(a[i] - a[i - 1]);
    }
    cout << result;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc010_explore