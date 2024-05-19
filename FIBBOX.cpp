/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 17:34:30 - 19/05/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)

using namespace std;

const int N     = 1e3 + 3;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, q, l, r, a[N];
char type;
map<int, int> F;

int f(int n){
    if (F.count(n)) return F[n];
    int k = n >> 1;
    if (n & 1) return F[n] = (f(k + 1) * f(k) + f(k) * f (k - 1)) % MOD;
    return F[n] = (f(k) * f(k) + f (k - 1) * f(k - 1)) % MOD;
}

int fibo(int n){
    return (!n ? 0 : f(n - 1));
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    cin >> n >> q;
    F[0] = F[1] = 1;
    while (q--){
        cin >> type >> l >> r;
        if (type == 'D'){
            forUp(i, l, r, 1) a[i]++;
        }
        else{
            int s = 0;
            forUp(i, l, r, 1) (s += fibo(a[i])) %= MOD;
            cout << s << endl;
        }
    }

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fct005_fibbox