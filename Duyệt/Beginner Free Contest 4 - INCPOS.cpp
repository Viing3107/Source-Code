#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;

int n, q, a[N], diff[N], cnt;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(diff, -0x3f, sizeof diff);
    for (int i = 1; i < n; i++) {
        diff[i] = a[i] - a[i + 1];
        cnt += diff[i] > 0;
    }
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        if (diff[l - 1] <= 0) cnt += diff[l - 1] - x > 0;
        else cnt -= diff[l - 1] - x <= 0;
        diff[l - 1] -= x;
        if (diff[r] <= 0) cnt += diff[r] + x > 0;
        else cnt -= diff[r] + x <= 0;
        diff[r] += x;
        cout << cnt << endl;
    }

    cerr << "Run Finished";
}

// https://oj.vnoi.info/problem/fcb004_incpos