/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 10:35:53 - 03/06/2024

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

int n, k;
string s;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> k >> s;
    for (int i = 0; i <= n - 2 && k; i++) if (s[i] == '4' && s[i + 1] == '7'){
        if (i % 2 == 0 && i <= n - 3 && s[i + 2] == '7'){
            if (k % 2) s[i + 1] = '4';
            cout << s;
            return (0 ^ 0);
        }
        if (i % 2 && i > 0 && s[i - 1] == '4'){
            if (k % 2) s[i] = '7';
            cout << s;
            return (0 ^ 0);
        }
        else{
            if (i % 2 == 0) s[i + 1] = '4';
            else{
                s[i] = '7';
                i -= 2;
            }
            k--;
        }
    }
    
    cout << s;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc081_transform