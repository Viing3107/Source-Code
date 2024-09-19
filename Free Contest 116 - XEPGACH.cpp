#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 5;

int n;

struct brick {
    int x, y;

    friend bool operator < (const brick &u, const brick &v) {
        return u.x - u.y > v.x - v.y;
    }
} a[N];

/*
    a[i] * (j - 1) + b[i] * (n - j)
    = b[i] * n - a[i] + (a[i] - b[i]) * j

    Nhận xét: b[i] * n - a[i]. không đổi nên ta chỉ cần sắp xếp sao cho (a[i] - b[i]) * j nhỏ nhất
    Thuật toán:
        Gọi diff[i] = a[i] - b[i]
        Sắp xếp diff[i] giảm dần
*/

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1);
    int res = 0;
    for (int i = 1; i <= n; i++) res += a[i].x * (i - 1) + a[i].y * (n - i);
    cout << res;
}
