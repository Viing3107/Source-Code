/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 16:45:32 - 20/07/2025

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

const int       N           = 1e6 + 5;
const int       VAL         = 1e6 + 6;
const int       MOD         = 1e9 + 7;
const int       BLOCK_SIZE  = sqrt(N);
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int q, type;
string s;

struct Trie {
    int child[N][26], isEnd[N], numNode;

    Trie() {
        memset(child, 0, sizeof child);
        memset(isEnd, 0, sizeof isEnd);
        numNode = 0;
    }

    void add(string &s) {
        int u = 0;
        forUp(i, 0, SZ(s) - 1, 1) {
            if (!child[u][s[i] - 'a']) child[u][s[i] - 'a'] = ++numNode;
            u = child[u][s[i] - 'a'];
        }
        isEnd[u]++;
    }

    int getPrefix(string &s) {
        int u = 0, res = 0;
        forUp(i, 0, SZ(s) - 1, 1) {
            if (!child[u][s[i] - 'a']) break;
            u = child[u][s[i] - 'a'];
            res += isEnd[u];
        }
        return res;
    }

    int res;
    void DFS(int u) {
        res += isEnd[u];
        forUp(i, 0, 25, 1) if (child[u][i]) DFS(child[u][i]);
    }

    int get(string &s) {
        int u = 0;
        forUp(i, 0, SZ(s) - 1, 1) {
            if (!child[u][s[i] - 'a']) return 0;
            u = child[u][s[i] - 'a'];
        }
        res = 0;
        DFS(u);
        return res;
    }
} pt;

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
        cin >> type >> s;
        if (!type) pt.add(s);
        else if (type == 1) cout << pt.getPrefix(s) << endl;
        else cout << pt.get(s) << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/fc098_pizza