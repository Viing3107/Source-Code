#include <bits/stdc++.h>
#define int long long
#define double long double

using namespace std;

const int N = 2e5 + 5;

int n;

struct house {
    int x, cnt, id;
} a[N];

/*

Tags: Math, Statistics, Binary Search + Big Number uses `long double`
Có 3 cách khác nhau để giải bài này:

Trước tiên ta sort theo tọa độ
C1 : Đáp án chính là trung vị
C2 & C3 :
    Nhận xét: Sau khi sort theo tọa độ, hàm f(x) liên tục, xác định trên [1, n] và là hàm Parabol
    Từ đây bài toán trở về tìm cực trị của f(x)
    C2 : Sử dụng đạo hàm
    C3 : Khử tam phân

*/

double f(int idx) {
    double ans = 0;
    for (int i = 1; i <= n; i++) ans += 1.0 * a[i].cnt * abs(a[i].x - a[idx].x);
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].cnt;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, [&] (const house &u, const house &v) -> bool {
        return u.x < v.x;
    });
    int l = 1, r = n;
    while (r - l > 4) {
        int m = l + r >> 1;
        if (f(m) <= f(m + 1)) r = m + 1;
        else l = m;
    }
    double minVal = 1;
    int idx;
    for (int i = 1; i <= 25; i++) minVal = minVal * 10;
    for (int i = l; i <= r; i++) {
        double val = f(i);
        if (val < minVal) {
            minVal = val;
            idx = a[i].id;
        }
        else if (val == minVal) idx = max(idx, a[i].id);
    }
    cout << idx;

    cerr << "Run Finished";
}

// https://oj.vnoi.info/problem/fcb041_meeting
