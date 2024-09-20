#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = (1ll << 21);

int n, s, w[N], v[N], res, preMax[N], wL[N];
vector<pair<int, int> > L, R;

bool cmp(const pair<int, int> &u, const pair<int, int> &v) {
    return u.first == v.first ? u.second > v.second : u.first < v.first;
}

void backtrack(int i, int weight, int value, int n, int state) {
    if (i > n) {
        if (weight <= s) {
            if (!state) L.push_back(make_pair(weight, value));
            else R.push_back(make_pair(weight, value));
        }
        return;
    }
    backtrack(i + 1, weight, value, n, state);
    backtrack(i + 1, weight + w[i], value + v[i], n, state);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
    int m = n >> 1;
    backtrack(1, 0, 0, m, 0);
    sort(L.begin(), L.end(), [&] (const pair<int, int> &u, const pair<int, int> &v) -> bool {
        return u.first == v.first ? u.second > v.second : u.first < v.first;
    });
    backtrack(m + 1, 0, 0, n, 1);
    for (int i = 0; i < L.size(); i++) {
        wL[i + 1] = L[i].first;
        preMax[i + 1] = max(preMax[i], L[i].second);
    }
    for (int i = 0; i < R.size(); i++) {
        int idx = upper_bound(wL + 1, wL + L.size() + 1, s - R[i].first) - wL - 1;
        res = max(res, R[i].second + preMax[idx]);
    }
    cout << res;
}

// https://marisaoj.com/problem/111
