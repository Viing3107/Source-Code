/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 20:08:02 - 15/08/2024

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
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e5 + 5;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int BLOCK_SIZE    = sqrt(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int q, n, a[N], answer[N];
deque<int> idx[N];

struct SparseTable {
    int maxVal[N][LOG];

    void build() {
        memset(maxVal, 0, sizeof maxVal);
        forUp(i, 1, n, 1) maxVal[i][0] = a[i];
        for (int j = 1; MASK(j) <= n; j++) for (int i = 1; i + MASK(j) - 1 <= n; i++) 
            maxVal[i][j] = max(maxVal[i][j - 1], maxVal[i + MASK(j - 1)][j - 1]);
    }

    int get(int l, int r) {
        if (l > r) return -INF;
        int k = __lg(r - l + 1);
        return max(maxVal[l][k], maxVal[r - MASK(k) + 1][k]);
    }
} st;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }


    cin >> q;
    while (q--) {
        vector<int> v;
        cin >> n;
        forUp(i, 1, n, 1) {
            cin >> a[i];
            v.push_back(a[i]);
        }
        sort(all(v));
        v.resize(unique(all(v)) - v.begin());
        forUp(i, 1, n, 1) a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
        st.build();
        memset(answer, 0, sizeof answer);

        forUp(i, 1, n, 1) idx[i].clear();
        forDown(i, n, 1, -1) {
            while (!idx[a[i]].empty() && st.get(i + 1, idx[a[i]].back() - 1) > a[i]) idx[a[i]].pop_back();
            answer[i] += idx[a[i]].size();
            idx[a[i]].push_front(i);
        }

        forUp(i, 1, n, 1) idx[i].clear();
        forUp(i, 1, n, 1) {
            while (!idx[a[i]].empty() && st.get(idx[a[i]].front() + 1, i - 1) > a[i]) idx[a[i]].pop_front();
            answer[i] += idx[a[i]].size();
            idx[a[i]].push_back(i);
        }

        forUp(i, 1, n, 1) cout << answer[i] << " ";
        cout << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb034_height