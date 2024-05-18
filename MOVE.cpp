/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)

using namespace std;

const int N     = 1e5 + 5;

int n, m, X1, Y1, X2, Y2, dx, dy;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    cin >> n >> m >> X1 >> Y1 >> X2 >> Y2;
    dx = abs(X1 - X2);
    dy = abs(Y1 - Y2);
    if (dx & 1 || dy & 1) cout << -1;
    else cout << dx / 2 + dy / 2;

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fct012_move