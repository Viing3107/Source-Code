#include <bits/stdc++.h>
#define int long long
#define task "test"
#define forEach(it, v) for(typeof v.begin() it = v.begin(), _e = v.end(); it != _e; it++)
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)

using namespace std;

const int N = 1e6 + 6;
int n, k, a[N], f[N];
deque<int> Q;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> k;
    forUp(i, 1, n, 1) cin >> a[i];
    forUp(i, 1, n, 1){
        while (!Q.empty() && a[Q.back()] > a[i]) Q.pop_back();
        Q.push_back(i);
        while (i - Q.front() >= k) Q.pop_front();
        f[i] = a[Q.front()];
    }

    forUp(i, k, n, 1) cout << f[i] << " ";

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}

/*
    /\_/\
   (= ._.)
   />0   \>1 VOI

*/