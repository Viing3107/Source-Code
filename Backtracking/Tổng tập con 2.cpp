#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

const int N = (1ll << 21);

int n, k, a[N];
vector<int> L;
string res = "NO";

void backtrack(int i, int s, int n, int state) {
    if (i > n || s > k) {
        if (s <= k) {
            if (!state) L.push_back(s);
            else if (binary_search(L.begin(), L.end(), k - s)) res = "YES";
        }
        return;
    }
    backtrack(i + 1, s, n, state);
    backtrack(i + 1, s + a[i], n, state);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int m = n >> 1;
    backtrack(1, 0, m, 0);
    sort(L.begin(), L.end());
    backtrack(m + 1, 0, n, 1);
    cout << res;
}

// https://marisaoj.com/problem/329
