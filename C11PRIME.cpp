# include <bits/stdc++.h>
# define int long long
# define task "test"

using namespace std;

int n, p;

bool isPrime(int n){
    if (n < 2 || n == 4) return false;
    if (n == 2 || n == 3 || n == 5) return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;
    for (int x = 5; x * x <= n; x += 6)
        if (n % x == 0 || n % (x + 2) == 0) return false;
    return true;
}

int pw(int x, int n){
    int res = 1;
    for (n; n; n >>= 1, x *= x){
        if (n & 1) res *= x;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    for (int q = 2; q <= 60; ++q){
        p = pow(n, double(1.0) / q);
        while (pw(p, q) < n) ++p;
        while (pw(p, q) > n) --p;
        if (pw(p, q) == n){
            if (isPrime(p)){
                cout << p << " " << q;
                return 0;
            }
        }
    }
    cout << 0;

    return 0;
}

// https://oj.vnoi.info/problem/c11prime
