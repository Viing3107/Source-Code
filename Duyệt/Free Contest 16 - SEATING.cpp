/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:39:01 - 14/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 55;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, m, k, a, b, result;
map<int, set<int>> mp;

/*
    seat[i][j] = 0 / 1 : ghế thứ j của hàng ghế cnt[i][0] đã có người ngồi

*/

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m >> k;
    forUp(i, 1, k, 1) {
        cin >> a >> b;
        mp[a].insert(b);
        mp[a].insert(m + 1);
    }
    // for (auto &it : mp) {
    //     set<int> tmp = it.second;
    //     for (set<int>::iterator x = tmp.begin(); x != tmp.end(); x++) cout << (*x) << " ";
    //     cout << endl;
    // }
    for (auto &it : mp) {
        set<int> tmp = it.second;
        for (set<int>::iterator x = tmp.begin(); x != tmp.end(); x++) {
            if (x == tmp.begin()) result += max(0ll, (*x) - 2);
            else {
                set<int>::iterator y = --x;
                ++x;
                result += max(0ll, (*x) - (*y) - 2);   
            }
        }
    }
    cout << result + (n - mp.size()) * (m - 1);
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc016_seating