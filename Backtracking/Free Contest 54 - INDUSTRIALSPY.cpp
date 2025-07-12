#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define SZ(v)                   (int) (v).size()
#define ALL(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)


using namespace std;

int t, mark[10], isFinal;
string s;
vector<int> prime, lpf;
unordered_set<int> res;

void sieve(int n) {
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);
    forUp (x, 3, n, 2) {
        if (lpf[x] == 2) prime.push_back(lpf[x] = x);
        for (int i = 0; prime[i] <= lpf[x] && prime[i] * x <= n; i++) lpf[prime[i] * x] = prime[i];
    }
}

bool isPrime(int n) {return n >= 2 && lpf[n] == n;}

void nextPermutation() {
    int i = SZ(s) - 1;
    for (; i >= 0 && mark[i]; i--) mark[i] = 0;
    if (i == -1) isFinal = 1;
    else mark[i] = 1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    sieve(1e7);
    cin >> t;
    while (t--) {
        //reset
        memset(mark, 0, sizeof mark);
        res.clear();
        isFinal = 0;
        //solve
        cin >> s;
        while (!isFinal) {
            string t = "";
            forUp (i, 0, SZ(s) - 1, 1) if (mark[i]) t += s[i];
            sort(ALL(t));
            do {
                if (t != "" && t[0] != '0' && isPrime(stoll(t))) res.insert(stoll(t));
            } while (next_permutation(ALL(t)));
            nextPermutation();
        }
        cout << SZ(res) << endl;
    }
}

// https://oj.vnoi.info/problem/fc054_industrialspy
