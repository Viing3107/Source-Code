# include <bits/stdc++.h>
# define int unsigned long long
# define task "test"

using namespace std;

const int LIM = 1e6 + 6;
int a, b, c, y, cnt, res, mark1[LIM], mark2[LIM], mark3[LIM];
vector<int> prime, lpf;
map<int, int> mp;

void sieve(int n){
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);
    for (int x = 3; x <= n; x += 2){
        if (lpf[x] == 2) prime.push_back(lpf[x] = x);
        for (int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; i++)
            lpf[prime[i] * x] = prime[i];
    }
}

int gcd(int a, int b){
    if (!a) return b;
    return gcd(b % a, a);
}

int lcm(int a, int b){
    return a / gcd(a, b) * b;
}

int binaryExponentiaiton(int a, int b){
    int res = 1;
    while (b){
        if (b & 1) res *= a;
        b >>= 1;
        a *= a;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> a >> b >> c;

    sieve(LIM);
    while (a != 1){
        y = lpf[a];
        while (a % y == 0){
            mark1[y]++;
            a /= y;
        }
    }
    while (b != 1){
        y = lpf[b];
        while (b % y == 0){
            mark2[y]++;
            b /= y;
        }
    }
    while (c != 1){
        y = lpf[c];
        while (c % y == 0){
            mark3[y]++;
            c /= y;
        }
    }
    res = 1;
    for (int i = 2; i <= 1e6; i++){
        y = max({mark1[i], mark2[i], mark3[i]});
        res *= binaryExponentiaiton(i, y / 2 + (y % 2));
    }

    cout << res;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}

// https://oj.vnoi.info/problem/tht21_tphcm_slc_square