/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:43:31 - 20/07/2025

*/

#include                        <iostream>
#include                        <unordered_map>
#define task                    "test"
#define SZ(v)                   (int) (v).size()
#define forUp(i, l, r, step)    for (short i = (l); i <= (r); i += step)

using namespace std;

const short       BASE        = 311;
const short       N           = 5e3 + 5;

int MOD[] = {1000003, 1000000007};
short n;
long long hashS[2][N], p[2][N];
string s;
int child[N * N][2];

struct cmp {
    template <class T1, class T2>
    long long operator () (const pair<T1, T2> &p) const {
        long long h1 = hash<T1>{}(p.first);
        long long h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

unordered_map<pair<long long, long long>, bool, cmp> res;

long long getHash(int i, int l, int r) {
    return ((hashS[i][r] - hashS[i][l - 1] * p[i][r - l + 1]) % MOD[i] + MOD[i]) % MOD[i];
}

void subtask1() {
    forUp(i, 1, n, 1) forUp(j, i, n, 1) res[{getHash(0, i, j), getHash(1, i, j)}] = true;
    cout << SZ(res);
}

void subtask2() {
    int res = 0;
    forUp(i, 1, n, 1) {
        int u = 0;
        forUp(j, i, n, 1) {
            short k = s[j] - 'a';
            if (!child[u][k]) child[u][k] = ++res;
            u = child[u][k];
        }
    }
    cout << res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> s;
    n = SZ(s);
    s = " " + s;
    p[0][0] = p[1][0] = 1;
    forUp(i, 0, 1, 1) forUp(j, 1, n, 1) {
        hashS[i][j] = (hashS[i][j - 1] * BASE + (int) s[j]) % MOD[i];
        p[i][j] = (p[i][j - 1] * BASE) % MOD[i];
    }
    if (n <= 1000) subtask1();
    else subtask2();
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/fc103_diffstr