#include <bits/stdc++.h>

using namespace std;

long long q, l, r;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> l >> r;
        long long res = 0;
        while (l % 9 && l <= r) {
            res += l % 9;
            l++;
        }
        while (r % 9 && l <= r) {
            res += r % 9;
            r--;
        }
        if (l <= r) res += (r - l) * 5 + 9;
        cout << res << endl;
    }
}

// https://oj.vnoi.info/problem/coci1920_r1_trol
