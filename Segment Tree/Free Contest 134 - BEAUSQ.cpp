/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 11:03:42 - 14/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 2e4 + 4;
const int LIM   = 1e6 + 6;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, q, a[N], type, l, r, idx, val;
vector<int> prime, lpf;

void sieve(int n) {
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);
    forUp(x, 3, n, 2) {
        if (lpf[x] == 2) prime.push_back(lpf[x] = x);
        for (int i = 0; prime[i] <= lpf[x] && prime[i] * x <= n; i++)
            lpf[prime[i] * x] = prime[i];
    }
}

vector<int> cntdiv(int n) {
    vector<int> res(102, 0);
    for (int y = lpf[n]; n != 1; y = lpf[n]) for (; n % y == 0; n /= y) res[y]++;
    return res;
}

struct SegmentTree{
    vector<int> st[4 * N], empty;

    SegmentTree() {
        forUp(i, 1, 8e4, 1) st[i].assign(102, 0);
        empty.assign(102, 0);
    }

    vector<int> merge(vector<int> u, vector<int> v) {
        forUp(i, 2, 100, 1) u[i] += v[i];
        return u;
    }

    void build(int id, int l, int r) {
        if (l == r) {
            st[id] = cntdiv(a[l]);
            return;
        }
        int m = l + r >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        st[id] = merge(st[id * 2], st[id * 2 + 1]);
    }

    void update(int id, int l, int r, int idx, int val) {
        if (idx < l || idx > r) return;
        if (l == r) {
            st[id] = merge(st[id], cntdiv(val));
            return;
        }
        int m = l + r >> 1;
        update(id * 2, l, m, idx, val);
        update(id * 2 + 1, m + 1, r, idx, val);
        st[id] = merge(st[id * 2], st[id * 2 + 1]);
    }

    vector<int> get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return empty;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        return merge(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
    }
} it;

void answer(int l, int r) {
    vector<int> tmp = it.get(1, 1, n, l, r);
    forUp(i, 2, 100, 1) {
        if (tmp[i] % 2) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    sieve(LIM);
    cin >> n;
    forUp(i, 1, n, 1) cin >> a[i];
    it.build(1, 1, n);
    cin >> q;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> l >> r;
            answer(l, r);
        }
        else {
            cin >> idx >> val;
            it.update(1, 1, n, idx, val);
        }
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc134_beausq