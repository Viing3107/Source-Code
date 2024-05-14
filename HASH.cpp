/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)

using namespace std;

const int N     = 3e5 + 5;
const int LIM   = 5e2 + 2;
const int INF   = 0x3f3f3f3f3f3f3f3f;
const int MOD   = 1e9 + 7;
const int base  = 33;

string s, t;
int q, hashS[N], n, power[N], l, r;

int getHash(int l, int r){
    return ((hashS[r] - hashS[l - 1] * power[r - l + 1]) % MOD + MOD) % MOD;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> s;
    n = s.size();
    s = " " + s;
    forUp(i, 1, n, 1) hashS[i] = (hashS[i - 1] * base + s[i] - 'a' + 1) % MOD;
    power[0] = 1;
    forUp(i, 1, n, 1) power[i] = (power[i - 1] * base) % MOD;
    cin >> q;
    while (q--){
        cin >> l >> r;
        cout << getHash(l, r) << endl;
    }

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc058_hash