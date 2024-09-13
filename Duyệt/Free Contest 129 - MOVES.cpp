#include <bits/stdc++.h>
#define int long long
#define double long double

using namespace std;

const int N = 1e3 + 3;

int q, n, d, a[N];

void solve() {
    cin >> n >> d;
    int s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    if (n & 1) {
        if (s <= n / 2 * d + d) cout << "YES\n";
        else cout << "NO\n";
    }
    else {
        if (s <= n / 2 * d) cout << "YES\n";
        else cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> q;
    while (q--) solve();
}

// https://oj.vnoi.info/problem/fc129_moves
