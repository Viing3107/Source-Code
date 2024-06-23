/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 10:06:52 - 23/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "CAU2"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, m, result;

struct flower{
    int cost, amount;

    friend bool operator < (flower u, flower v){
        return (u.cost != v.cost) ? u.cost < v.cost : u.amount < v.amount;
    }
} a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m;
    forUp(i, 1, n, 1) cin >> a[i].cost >> a[i].amount;
    sort(a + 1, a + n + 1);
    forUp(i, 1, n, 1){
        if (a[i].cost > m) break;
        int tmp = min(a[i].amount, m / a[i].cost);
        result += tmp;
        m -= a[i].cost * tmp;
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

// 