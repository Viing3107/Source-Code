/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 17:25:48 - 20/07/2025

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
    struct node {
        int child[26], cnt, exist;

        /*
        cnt: số lượng xâu đi qua hoặc kết thúc tại u
        exist: số lượng xâu kết thúc tại u
        */
    };

    node T[N];
    int numNode;
    
    Trie() {
        forUp(i, 0, N - 1, 1) {
            memset(T[i].child, 0, sizeof T[i].child);
            T[i].cnt = T[i].exist = 0;
        }
        numNode = 0;
    }

    void add(string &s) {
        int u = 0;
        forUp(i, 0, SZ(s) - 1, 1) {
            int k = s[i] - 'a';
            if (!T[u].child[k]) T[u].child[k] = ++numNode;
            u = T[u].child[k];
            T[u].cnt++;
        }
        T[u].exist++;
    }

    // số xâu là tiền tố của s
    int get1(string &s) {
        int u = 0, res = 0;
        forUp(i, 0, SZ(s) - 1, 1) {
            int k = s[i] - 'a';
            if (!T[u].child[k]) break;
            u = T[u].child[k];
            res += T[u].exist;
        }
        return res;
    }

    // số xâu nhận s là tiền tố
    int get2(string &s) {
        int u = 0;
        forUp(i, 0, SZ(s) - 1, 1) {
            int k = s[i] - 'a';
            if (!T[u].child[k]) return 0;
            u = T[u].child[k];
        }
        return T[u].cnt;
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
        else if (type == 1) cout << pt.get1(s) << endl;
        else cout << pt.get2(s) << endl;
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
