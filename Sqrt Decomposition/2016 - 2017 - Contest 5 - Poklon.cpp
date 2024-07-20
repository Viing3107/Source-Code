/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 18:27:31 - 20/07/2024

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

const int N             = 5e5 + 5;
const int BLOCK_SIZE    = 710;
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, q, a[N], answer[N], cnt[N];

struct query{
    int l, r, id;

    friend bool operator < (query u, query v) {
        return ((u.l / BLOCK_SIZE == v.l / BLOCK_SIZE) ? u.r < v.r : u. l < v.l);
    }
} Q[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> q;
    vector<int> v;
    forUp(i, 1, n, 1) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    forUp(i, 1, n, 1) a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;

    forUp(i, 1, q, 1) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].id = i;
    }
    
    sort(Q + 1, Q + q + 1);

    int l = 1, r = 0, result = 0;
    forUp(i, 1, q, 1) {
        int u = Q[i].l, v = Q[i].r;
        while (l < u) {
            cnt[a[l]]--;
            if (cnt[a[l]] == 1) result--;
            else if (cnt[a[l]] == 2) result++;
            l++;
        }
        while (l > u) {
            l--;
            if (cnt[a[l]] == 1) result++;
            if (cnt[a[l]] == 2) result--;
            cnt[a[l]]++;
        }
        while (r < v) {
            r++;
            if (cnt[a[r]] == 1) result++;
            else if (cnt[a[r]] == 2) result--;
            cnt[a[r]]++;
        }
        while (r > v) {
            cnt[a[r]]--;
            if (cnt[a[r]] == 1) result--;
            else if (cnt[a[r]] == 2) result++;
            r--;
        }
        answer[Q[i].id] = result;
    }
    forUp(i, 1, q, 1) cout << answer[i] << endl;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/coci1617_r5_poklon