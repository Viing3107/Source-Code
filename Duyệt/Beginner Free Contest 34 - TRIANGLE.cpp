/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 20:11:48 - 25/05/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int t, n, result;
pair<int, int> a[N];

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
        result = 0;
        forUp(i, 1, n, 1){
            cin >> a[i].first >> a[i].second;
            result = max(result, a[i].first + a[i].second);
        }
        cout << result << endl;
    }

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb034_triangle