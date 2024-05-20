/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 13:07:38 - 20/05/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define task                    "CANDIES"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, a[N], cnt, answer, s;

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
        cin >> a[i];
        if (a[i] % 3 == 0 && a[i]){
            cnt++;
            s += a[i];
        }
    }
    cout << cnt << " ";
    s -= 3 * cnt;
    cout << s / 3;

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 
