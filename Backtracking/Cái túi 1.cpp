#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = (1ll << 20);

struct gold {
    int weight, val;

    friend bool operator < (const gold &u, const gold &v) {
        return u.weight == v.weight ? u.val > v.val : u.weight < v.weight;
    }
} a[N];

vector<gold> L, R;
int preMax[N], wR[N];
int n, m, answer;

void backtrack(int i, int weight, int val, int state) {
    if (!state) {
        if (i * 2 > n) {
            if (weight <= m) L.push_back({weight, val});
            return;
        }
    }
    else {
        if (i > n) {
            if (weight <= m) R.push_back({weight, val});
            return;
        }
    }
    backtrack(i + 1, weight, val, state);
    backtrack(i + 1, weight + a[i].weight, val + a[i].val, state);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i].weight >> a[i].val;
    backtrack(1, 0, 0, 0);
    // for (auto &x : L) cout << x.first << " " << x.second << endl;
    backtrack(n / 2 + 1, 0, 0, 1);
    sort(R.begin(), R.end());
    // for (auto &x : R) cout << x.first << " " << x.second << endl;
    for (int i = 0; i < R.size(); i++) {
        wR[i] = R[i].weight;
        preMax[i] = !i ? R[i].val : max(preMax[i - 1], R[i].val);
    }
    for (auto &x : L) {
        int idx = upper_bound(wR, wR + R.size(), m - x.weight) - wR - 1;
        answer = max(answer, x.val + preMax[idx]);
    }
    cout << answer;
}

// https://oj.vnoi.info/problem/dttui1