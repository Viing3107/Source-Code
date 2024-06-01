/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 08:07:25 - 01/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int t, result, old;
string s;
map<string, int>mp = {{"ABSINTH", 1}, {"TEQUILA", 1}, {"VODKA", 1}, {"WHISKEY", 1}, {"WINE", 1}, {"BEER", 1}, {"BRANDY", 1}, {"CHAMPAGNE", 1}, {"GIN", 1}, {"RUM", 1}, {"SAKE", 1}};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> t;
    while (t--){
        cin >> s;
        if (isdigit(s[0])){
            old = stoll(s);
            result += (old < 18);
        }
        else result += mp[s];
    }
    cout << result;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc068_alcohol