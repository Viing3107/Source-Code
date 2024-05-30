/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 16:44:03 - 30/05/2024

*/
#include                        <bits/stdc++.h>
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define pi                      M_PI
#define eps                     1e-6

using namespace std;

const int N     = 1e2 + 2;
const int MOD   = 1e9 + 7;

int q, present, last;
string s;
double circuit, S, res;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> q;
    cin.ignore();
    circuit = 60 * pi;
    while(q--){
        getline(cin, s);
        res = 1;
        forUp(i, 0, s.size() - 1, 1){
            if (isupper(s[i])) s[i] += 32;
        }
        last = (s[0] == 39 ? 28 : s[0] == ' ' ? 27 : s[0] - 'a' + 1);
        forUp(i, 1, s.size() - 1, 1){
            present = (s[i] == 39 ? 28 : s[i] == ' ' ? 27 : s[i] - 'a' + 1);
            if (last >= present) S = min(last - present, 28 - (last - present));
            else S = min(present - last, 28 - (present - last));
            S = S * circuit / 28.0;
            res += S / 15.0;
            res++;
            last = present;
        }
        cout << fixed << setprecision(4) << res << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb008_inspire

// Nháp và mọi thứ mình để ở đây :