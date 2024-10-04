/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 17:41:40 - 04/10/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define SZ(v)                   (int) v.size()
#define all(v)                  v.begin(), v.end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof v.begin() it = v.begin(), _e = it.end(); it != _e; it++)

using namespace std;

const int N             = 5e5 + 5;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int BLOCK_SIZE    = sqrt(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

struct point {
    double x, y, w;

    friend istream &operator >> (istream &stream, point &p) {
        stream >> p.x >> p.y >> p.w;
        return stream;
    }

    friend bool operator < (const point &u, const point &v) {
        return pow(u.x, 2) + pow(u.y, 2) < pow(v.x, 2) + pow(v.y, 2);
    }
};

struct query {
    double r;
    int id;

    friend bool operator < (const query &u, const query &v) {
        return u.r < v.r;
    }
};

int n, q, ans[N];
point a[N];
vector<query> queries;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= q; i++) {
        int r;
        cin >> r;
        queries.push_back({pow(r, 2), i});
    }
    sort(all(queries));
    int res = 0;
    for (int i = 0, idx = 1; i < q; i++) {
        for (; idx <= n && pow(a[idx].x, 2) + pow(a[idx].y, 2) <= queries[i].r; idx++) res += a[idx].w;
        ans[queries[i].id] = res;
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << endl;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bedao_g17_a