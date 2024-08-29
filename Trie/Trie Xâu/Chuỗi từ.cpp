#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 25e4 + 4;

int n, result;
string s;

struct Trie {
    int child[N][26], isEnd[N];
    int cur;

    Trie() {
        cur = 0;
        memset(child, 0, sizeof child);
        memset(isEnd, 0, sizeof isEnd);
    }

    void insert(const string &s, int u = 0) {
        for (auto &c : s) {
            int k = c - 'a';
            if (!child[u][k]) child[u][k] = ++cur;
            u = child[u][k];
        }
        isEnd[u] = 1;
    }

    int DFS(int u = 0) {
        int cnt = isEnd[u], val = 0;
        for (int k = 0; k < 26; k++) {
            if (child[u][k]) val = max(val, DFS(child[u][k]));
        }
        return cnt + val;
    }
} t;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        t.insert(s);
    }
    cout << t.DFS();
}

// https://oj.vnoi.info/problem/chain2