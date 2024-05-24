/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:38:44 - 24/05/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, cntDot, result, m;
string a[N], s;
bool isDot, givenName;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    cin >> n;
    while (cntDot < n){
        cin >> s;
        m = s.size();
        isDot = s[m - 1] == '.' || s[m - 1] == '?' || s[m - 1] == '!';
        givenName = isupper(s[0]);
        m -= isDot;
        forUp(i, 1, m - 1, 1) givenName = givenName && islower(s[i]);
        result += givenName;
        if (isDot){
            cntDot++;
            cout << result << endl;
            result = 0;
        }
    }

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/coci1617_r3_imena
