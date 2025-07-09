/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define BIT(i, n)               ((n) >> (i) & 1)
#define SZ(v)                   (int) (v).size()
#define ALL(v)                  (v).begin(), (v).end()
#define LOG(x)                  (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof v.begin() it = v.begin(); it != v.end(); it++)

using namespace std;

const int       N           = 1e6 + 5;
const int       BASE        = 31;
const int       MOD         = 1e9 + 7;
const int       BLOCK_SIZE  = sqrt(N) + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, q, h[N], query[N], a[N], b[N];
vector<int> v;

/*
vi h[i] <= 1e9  --> nen chieu cao
goi a[i] la chieu cao cua hoc sinh i sau khi nen
b[i] la so hoc sinh co chieu cao = i
khi them mot hoc sinh co chieu cao X vao:
    vi tri cua hoc sinh nay = b[1] + b[2] + ... + b[X] + 1
    b[X]++
*/

struct SegmentTree {
    int st[4 * N];

    void build(int id, int l, int r) {
        if (l == r) return void(st[id] = b[l]);
        int m = l + r >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    void update(int id, int l, int r, int idx) {
        if (idx < l || idx > r) return;
        if (l == r) {
            st[id]++;
            b[l]++;
            return;
        }
        int m = l + r >> 1;
        update(id * 2, l, m, idx);
        update(id * 2 + 1, m + 1, r, idx);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    int get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return 0;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
    }
} it;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> q;
    forUp (i, 1, n, 1) {
        cin >> h[i];
        v.push_back(h[i]);
    }
    forUp (i, 1, q, 1) {
        cin >> query[i];
        v.push_back(query[i]);
    }
    sort(ALL(v));
    v.resize(unique(ALL(v)) - v.begin());
//    for (auto &x : v) cout << x << " ";
//    cout << endl;
    forUp (i, 1, n, 1) {
        auto itr = lower_bound(ALL(v), h[i]);
        a[i] = itr - v.begin() + 1;
    }
//    forUp (i, 1, n, 1) cout << a[i] << " ";
//    cout << endl;
    forUp (i, 1, n, 1) b[a[i]]++;
//    forUp (i, 1, 1e6, 1) cout << b[i] << endl;
    it.build(1, 1, 1e6);
    forUp (i, 1, q, 1) {
        int x = lower_bound(ALL(v), query[i]) - v.begin() + 1;
        cout << it.get(1, 1, 1e6, 1, x) + 1 << endl;
        it.update(1, 1, 1e6, x);
    }

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 Viing3107

*/

// https://oj.vnoi.info/problem/codetour24_c1_c
