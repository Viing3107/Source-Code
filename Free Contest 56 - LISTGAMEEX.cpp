/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 16:11:36 - 09/06/2024

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

int n;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    while (cin >> n){
        int i = 2;
        int result = 0;
        while (n != 1 && i * i <= n){
            while (n % i == 0){
                n /= i;
                result++;
            }
            while (n % (i + 2) == 0){
                result++;
                n /= i + 2;
            }
            if (i == 2) i++;
            else if (i == 3) i += 2;
            else i += 6;
        }
        if (n != 1) result++;
        cout << result << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc056_listgameex