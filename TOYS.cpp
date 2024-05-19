/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 10:05:53 - 19/05/2024

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

int n, m, a[N], i = 1;
vector<int> result;
map<int, int> mp;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    cin >> n >> m;
    forUp(i, 1, n, 1){
        cin >> a[i];
        mp[a[i]]++;
    }
    while (m >= i){
        if (!mp.count(i)){
            m -= i;
            result.push_back(i);
        }
        i++;
    }
    cout << result.size() << endl;
    for (auto it : result) cout << it << " ";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 
