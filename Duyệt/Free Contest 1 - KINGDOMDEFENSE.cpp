#include <bits/stdc++.h>

using namespace std;

const int N = 4e4 + 4;

int n, w, h, W[N], H[N];

struct point {
    int x, y;
} a[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> h >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1, [&] (const point &u, const point &v) {
        return u.x < v.x;
    });
    for (int i = 1; i <= n; i++) W[i] = a[i].x - a[i - 1].x - 1;
    W[n + 1] = w + 1 - a[n].x - 1;
    // for (int i = 1; i <= n + 1; i++) cout << W[i] << " \n"[i == n + 1];

    sort(a + 1, a + n + 1, [&] (const point &u, const point &v) {
        return u.y < v.y;
    });

    for (int i = 1; i <= n; i++) H[i] = a[i].y - a[i - 1].y - 1;
    H[n + 1] = h + 1 - a[n].y - 1;
    // for (int i = 1; i <= n + 1; i++) cout << H[i] << " \n"[i == n + 1];
    cout << *max_element(H + 1, H + n + 2) * *max_element(W + 1, W + n + 2);
}

// https://oj.vnoi.info/problem/fc001_kingdomdefense