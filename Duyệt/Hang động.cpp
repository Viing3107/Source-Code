#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 5;

int n, h, mark[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i & 1) {
            mark[1]++;
            mark[x + 1]--;
        }
        else mark[h - x + 1]++;
    }
    for (int i = 1; i <= h; i++) mark[i] += mark[i - 1];
    int minHigh = *min_element(mark + 1, mark + h + 1);
    cout << minHigh << " " << count(mark + 1, mark + h + 1, minHigh);
}

// https://oj.vnoi.info/problem/c11cave
