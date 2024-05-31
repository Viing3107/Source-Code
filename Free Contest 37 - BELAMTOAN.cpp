/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:07:26 - 31/05/2024

*/
#include                        <bits/stdc++.h>
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;

int t;
string s, res;
char a[] = {'+', '-', '*', '/'};
bool ok;

bool check(string A, char sign, string B, string RES){
    int a = stoll(A);
    int b = stoll(B);
    int res = stoll(RES);
    if (sign == '+') return a + b == res;
    else if (sign == '-') return a - b == res;
    else if (sign == '*') return a * b == res;
    return (a % b == 0 && a / b == res);
}

void recursive(int i){
    if (ok) return;
    if (i > 11){
        forUp(i, 0, 11, 1) if (s[i] == '?') return;
        if (check(s.substr(0, 2), s[3], s.substr(5, 2), s.substr(10, 2))){
            ok = true;
            cout << s << endl;
        }
        return;
    }
    if (s[i] == '?'){
        if (i == 0 || i == 5 || i == 10){
            for (char j = '1'; j <= '9' && !ok; j++){
                s[i] = j;
                recursive(i + 1);
                s[i] = '?';
            }
        }
        else if (i != 3){
            for (char j = '0'; j <= '9' && !ok; j++){
                s[i] = j;
                recursive(i + 1);
                s[i] = '?';
            }
        }
        else{
            for (int j = 0; j <= 3 && !ok; j++){
                s[3] = a[j];
                recursive(i + 1);
                s[3] = '?';
            }
        }
    }
    recursive(i + 1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> t;
    cin.ignore();
    while (t--){
        getline(cin, s);
        recursive(0);
        if (!ok) cout << "Leu leu, de bai co giao sai roi!\n";
        ok = false;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc037_belamtoan