/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:19:03 - 20/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "TEO"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 2e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

string s;
int n, a[N], idx, q;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> s;
    n = s.size();
    s = " " + s;
    cin >> q;
    while (q--){
        cin >> idx;
        a[idx]++;
        a[n - idx + 2]--;
    }
    forUp(i, 1, n, 1) a[i] += a[i - 1];
    for (int i = 1; i * 2 <= n; i++) if (a[i] % 2) swap(s[i], s[n - i + 1]);
    forUp(i, 1, n, 1) cout << s[i];
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 