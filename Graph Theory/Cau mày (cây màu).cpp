#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, BLOCK_SIZE = 450;
int n, c[N], tour[N], in[N], out[N], timer, cnt[N], ans[N];
vector<int> adj[N];
pair<int, int> q[N];

void DFS(int u, int par) {
    tour[++timer] = u;
    in[u] = timer;

    for (auto v : adj[u]) {
        if (v == par) continue;
        DFS(v, u);
    }

    out[u] = timer;
}

bool cmp(pair<int, int> u, pair<int, int> v) {
    if (u.first / BLOCK_SIZE == v.first / BLOCK_SIZE) return u.second < v.second;
    return u.first < v.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    if (fopen("test.inp", "r")){
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }


    // đọc cây và nén mảng c
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        v.push_back(c[i]);
    }

    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    for (int i = 1; i <= n; i++) c[i] = lower_bound(v.begin(), v.end(), c[i]) - v.begin() + 1;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // DFS cây để xây dựng mảng in[] và out[]
    DFS(1, 0);
    for (int i = 1; i <= n; i++) q[i] = {in[i], out[i]};
    
    // sort truy vấn, phục vụ cho Mo's Algorithms
    sort(q + 1, q + 1 + n, cmp);

    // Mo's Algorithms
    int res = 0, l = 1, r = 0;
    for (int i = 1; i <= n; i++) {
        int u = q[i].first, v = q[i].second;
        while (r < v) {
            r++;
            int color = c[tour[r]];
            if (cnt[color] == 0) res++;
            cnt[color]++;
        }

        while (l > u) {
            l--;
            int color = c[tour[l]];
            if (cnt[color] == 0) res++;
            cnt[color]++;
        }

        while (r > v) {
            int color = c[tour[r]];
            cnt[color]--;
            if (cnt[color] == 0) res--;
            r--;
        }

        while (l < u) {
            int color = c[tour[l]];
            cnt[color]--;
            if (cnt[color] == 0) res--;
            l++;
        }

        ans[tour[u]] = res;  // tour[u] là node nhận đoạn con a[u...v] là subtree
        // tour[u] <-> in[u] đều có ý nghĩa là đỉnh gốc của cây con từ in[u] đến out[u]
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/euler_d