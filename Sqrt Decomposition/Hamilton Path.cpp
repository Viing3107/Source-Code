#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
const int BLOCK_SIZE = 1e3;

int n;

struct point {
    int x, y, id;

    point () {x = 0, y = 0;}

    friend bool operator < (const point &u, const point &v) {
        if (u.x / BLOCK_SIZE != v.x / BLOCK_SIZE) return u.x < v.x;
        if (u.x / BLOCK_SIZE & 1) return u.y < v.y;
        return u.y > v.y;

    }
} a[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) cout << a[i].id << " ";
}

// https://oj.vnoi.info/problem/sqrt_d