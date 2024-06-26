/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 16:54:34 - 26/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 5e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, m, c1, c2, dist = INF, cnt;
vector<int> u, v;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m >> c1 >> c2;
    forUp(i, 1, n, 1){
        int x;
        cin >> x;
        u.push_back(x);
    }
    forUp(i, 1, m, 1){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());
    forUp(i, 0, u.size() - 1, 1){
        int r = lower_bound(v.begin(), v.end(), u[i]) - v.begin();
        int l = r - 1;
        dist = min({dist, abs(c1 - c2) + abs(u[i] - v[l]), abs(c1 - c2) + abs(u[i] - v[r])});
    }
    forUp(i, 0, u.size() - 1, 1){
        int r = lower_bound(v.begin(), v.end(), u[i]) - v.begin();
        int l = r - 1;
        cnt += (abs(c1 - c2) + abs(u[i] - v[l]) == dist);
        cnt += (abs(c1 - c2) + abs(u[i] - v[r]) == dist);
    }
    cout << dist << " " << cnt;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc062_closest