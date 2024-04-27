# include <bits/stdc++.h>
# define int long long
# define task "test"

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 5;
int n, a[N], res = -INF;

int solve(int i){
    if (i <= 1 || a[i] == 1) return max(res, a[i]);
    if (a[i - 1] < a[i]) return max(res, a[i] + solve(i - 1));
    if (a[i - 1] >= a[i] && a[i] >= 2){
        a[i - 1] = a[i] - 1;
        return max(res, a[i] + solve(i - 1)); 
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << solve(n);

    return (0 ^ 0);
}

/*
    /\_/\
   (= ._.)
   / >0  \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb032_socola