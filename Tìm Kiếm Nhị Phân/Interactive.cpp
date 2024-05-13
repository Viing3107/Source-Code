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

const int N     = 1e7 + 7;
const int LIM   = 1e7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int l = 0, r = 1e6 + 1, m, answer;
string s;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    while (r - l > 1){
        m = l + r >> 1;
        cout << m << endl;
        cin >> s;
        if (s == "<") r = m;
        else{
            answer = m;
            l = m;
        }
    }
    cout << "! " << answer << endl;

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 
