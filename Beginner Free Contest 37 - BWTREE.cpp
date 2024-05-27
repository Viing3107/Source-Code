/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 17:28:42 - 27/05/2024

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

int q, u, v;

void solve(){
    cin >> u >> v;
    vector<int> bitx, bity;
    for (; u; u >>= 1) bitx.push_back(u);
    for (; v; v >>= 1) bity.push_back(v);
    int X = bitx.size();
    int Y = bity.size();
    forUp(i, 0, X - 1, 1){
        forUp(j, 0, Y - 1, 1){
            if (bitx[i] == bity[j]){
                cout << bitx[i] << endl;
                return;
            }
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

    cin >> q;
    while (q--) solve();
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 