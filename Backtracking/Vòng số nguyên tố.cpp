
/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh

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
#define forEach(it, v)          for (typeof v.begin() it = v.begin(); it != v.end(); it++)

using namespace std;

const int       N           = 1e4 + 4;
const int       BASE        = 31;
const int       MOD         = 1e9 + 7;
const int       BLOCK_SIZE  = sqrt(N) + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, cnt, a[22];
bool used[22];
vector<int> res[N];
vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

bool isPrime(int n) {return binary_search(ALL(prime), n);}

void backtrack(int i) {
    if (i == n && isPrime(a[1] + a[n])) {
        cnt++;
        if (cnt <= 10000) forUp (j, 1, n, 1) res[cnt].push_back(a[j]);
        return;
    }
    for (auto &x : prime) {
        if ((!used[x - a[i]]) && (x - a[i] >= 1) && (x - a[i] <= n)) {
            a[i + 1] = x - a[i];
            used[x - a[i]] = true;
            backtrack(i + 1);
            a[i + 1] = 0;
            used[x - a[i]] = false;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    n *= 2;
    a[1] = 1;
    used[1] = true;
    backtrack(1);
    cout << cnt << endl;
    forUp (i, 1, min(cnt, 10000ll), 1) forUp (j, 0, n - 1, 1) cout << res[i][j] << " \n"[j == n - 1];

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 Viing3107

*/

// https://oj.vnoi.info/problem/pcircle
