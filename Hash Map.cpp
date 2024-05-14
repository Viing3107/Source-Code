/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define gcd(a, b)               __gcd(a, b)

using namespace std;

const int N     = 1e5 + 5;
const int LIM   = 5e2 + 2;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, k, a[N], answer, tmp;
double x;
map<int, int> mp;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    cin >> n >> k;
    forUp(i, 1, n, 1) cin >> a[i];
    forDown(i, n, 1, -1){
        mp[a[i]]++;
        x = k - a[i];
        if (x < 0) continue;
        tmp = sqrt(x);
        if (tmp * tmp == x) answer += mp[tmp];
        if (tmp) answer += mp[-tmp];
    }
    cout << answer;

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb001_c3
