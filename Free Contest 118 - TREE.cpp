/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:58:45 - 24/05/2024

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

int n, x, y;
vector<int> bitx, bity;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    cin >> n >> x >> y;
    for (; x; x >>= 1) bitx.push_back(x);
    for (; y; y >>= 1) bity.push_back(y);
    int X = bitx.size();
    int Y = bity.size();
    forUp(i, 0, X - 1, 1){
        forUp(j, 0, Y - 1, 1){
            if (bitx[i] == bity[j]){
                cout << i + j;
                return (0 ^ 0);
            }
        }
    }

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 
