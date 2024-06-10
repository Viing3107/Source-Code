/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:00:26 - 10/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 2e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, x, result[N], idx;
pair<int, int> a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    forUp(i, 1, n, 1){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    idx = n / 2;
    forUp(i, 1, n, 1){
        if (i <= idx) result[a[i].second] = a[idx + 1].first;
        else result[a[i].second] = a[idx].first;
    }
    forUp(i, 1, n, 1) cout << result[i] << endl;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc107_median