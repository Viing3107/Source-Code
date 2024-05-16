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

const int N     = 3e5 + 5;
const int LIM   = 5e2 + 2;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int t, n, m, a[N], b[N], numerator, denominator, tmp;
map<int, int> mp;

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
        cin >> n;
        forUp(i, 1, n, 1) cin >> a[i];
        cin >> m;
        forUp(i, 1, m, 1){
            cin >> b[i];
            mp[b[i]]++;
        }
        numerator = 0;
        denominator = n * m;
        sort(b + 1, b + m + 1);
        forUp(i, 1, n, 1) numerator += lower_bound(b + 1, b + m + 1, a[i]) - b - 1;
        tmp = gcd(numerator, denominator);
        numerator /= tmp;
        denominator /= tmp;
        cout << numerator << "/" << denominator << endl;

        numerator = 0;
        denominator = n * m;
        forUp(i, 1, n, 1) numerator += mp[a[i]];
        tmp = gcd(numerator, denominator);
        numerator /= tmp;
        denominator /= tmp;
        cout << numerator << "/" << denominator << endl;
        mp.clear();
    }

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc139_duels