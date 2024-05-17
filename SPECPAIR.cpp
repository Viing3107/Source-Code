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

const int N     = 2e5 + 5;
const int LIM   = 1e7 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, a[N], answer, mark[LIM]; 
vector<int> special;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    forUp(i, 1, 9, 1){
        int specialNumber = i;
        forUp(j, 1, 7, 1){
            special.push_back(specialNumber);
            specialNumber = specialNumber * 10 + i;
        }
    }
    cin >> n;
    forUp(i, 1, n, 1) cin >> a[i];
    forDown(i, n, 1, -1){
        for(auto it : special){
            if (it - a[i] > 0) answer += mark[it - a[i]];
        }
        mark[a[i]]++;
    }
    cout << answer;

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fct026_specpair