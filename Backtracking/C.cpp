/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 09:59:39 - 29/05/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 30;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, m, res;
pair<int, int> a[N];

void solve(int i, int weight, int value){
    if (i > n){
        res = max(res, value);
        return;
    }
    if (weight + a[i].first > m){
        res = max(res, value);
        return;
    }
    weight += a[i].first;
    value += a[i].second;
    solve(i + 1, weight, value);
    weight -= a[i].first;
    value -= a[i].second;
    solve(i + 1, weight, value);
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
    forUp(i, 1, n, 1) cin >> a[i].first >> a[i].second;
    solve(1, 0, 0);
    cout << res;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bvh_c