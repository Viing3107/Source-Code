/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 09:35:19 - 24/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "BAI4"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, d, r;
int day[N], night[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    while (cin >> n >> d >> r){
        if (!n && !d && !r) return (0 ^ 0);
        int result = 0;
        forUp(i, 1, n, 1) cin >> day[i];
        forUp(i, 1, n, 1) cin >> night[i];
        sort(day + 1, day + n + 1);
        sort(night + 1, night + n + 1, greater<int>());
        forUp(i, 1, n, 1) result += r * max(0ll, day[i] + night[i] - d);
        cout << result << "\n";
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 