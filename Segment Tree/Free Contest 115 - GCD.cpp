/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:13:40 - 25/07/2025

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
#define forEach(it, v)          for (typeof (v).begin() it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int       BASE        = 311;
const int       BLOCK_SIZE  = 320;
const int       N           = 1e5 + 5;
const int       VAL         = 1e6 + 6;
const int       MOD         = 1e9 + 7;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, a[N], cnt[N];
vector<int> v;

struct query {
    int type, val;
} q[N];

struct SegmentTree {
    int st[4 * N];

    void update(int id, int l, int r, int idx, int val) {
        if (idx < l || idx > r) return;
        if (l == r) return void(st[id] = val);
        int m = l + r >> 1;
        update(id * 2, l, m, idx, val);
        update(id * 2 + 1, m + 1, r, idx, val);
        st[id] = __gcd(st[id * 2], st[id * 2 + 1]);
    }

    int get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return 0;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        return __gcd(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
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

    cin >> n;
    forUp(i, 1, n, 1) {
        cin >> q[i].type >> q[i].val;
        if (q[i].type == 1) v.push_back(q[i].val);
    }
    sort(ALL(v));
    v.resize(unique(ALL(v)) - v.begin());
    forUp(i, 1, n, 1) {
        int idx = lower_bound(ALL(v), q[i].val) - v.begin() + 1;
        a[idx] = q[i].val;
        q[i].val = idx;
    }
    forUp(i, 1, n, 1) {
        if (q[i].type == 1) {
            if (!cnt[q[i].val]) it.update(1, 1, n, q[i].val, a[q[i].val]);
            cnt[q[i].val]++;
        }
        else {
            cnt[q[i].val]--;
            if (!cnt[q[i].val]) it.update(1, 1, n, q[i].val, 0);
        }
        int res = it.get(1, 1, n, 1, n);
        cout << (res ? res : 1) << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/fc115_gcd