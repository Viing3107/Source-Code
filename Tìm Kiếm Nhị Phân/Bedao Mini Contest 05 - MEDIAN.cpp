/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 11:19:55 - 30/05/2024

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

int n, x, e, res, l, r, Me;
vector<int> v = {0};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> x;
    forUp(i, 1, n, 1){
        cin >> e;
        v.push_back(e);
    }
    sort(v.begin(), v.end());
    if (!binary_search(v.begin(), v.end(), x)){
        res++;
        n++;
        v.push_back(x);
        sort(v.begin(), v.end());
    }
    Me = (n + 1) / 2;
    l = lower_bound(v.begin(), v.end(), x) - v.begin(); // x nằm ở bên trái
    r = upper_bound(v.begin(), v.end(), x) - v.begin() - 1; // x nằm ở bên phải
    if (Me < l){
        while (Me < l){
            res++;
            Me = ++n + 1 >> 1;
        }
        cout << res;
    }
    else if (Me >= l && Me <= r) cout << 0;
    else{
        while (Me > r){
            r++;
            res++;
            Me = ++n + 1 >> 1;
        }
        cout << res;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bedao_m05_median