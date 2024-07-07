#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        cout << ((n % (m + 1)) ? "A\n" : "B\n");
    }
}

// https://oj.vnoi.info/problem/bedao_m23_b