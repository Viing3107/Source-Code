# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
# define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
# define forEach(it, v) for(typeof(v.begin()) it = v.begin(), _e = v.end(); it != _e; it++)

using namespace std;

const int N = (1 << 20) + 2;
int n, a[N], x, y;

int solve(int x){ // solve(x) : số lượng dãy con có số phần tử khác nhau <= x
    if (!x) return 0;
    map<int, int> mp;
    int res = 0, cnt = 0;
    for (int l = 1, r = 1; r <= n; r++){
        mp[a[r]]++;
        cnt += (mp[a[r]] == 1);
        while (l < r && cnt > x){
            mp[a[l]]--;
            cnt -= (!mp[a[l]]);
            l++;
        }
        res += r - l + 1;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> x >> y;
    forUp(i, 1, n, 1) cin >> a[i];
    cout << solve(y) - solve(x - 1);

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}

/*
    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/sopenp