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

const int N     = 1e5 + 5;
const int LIM   = 1e5 + 5;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, BIT[N], a[N], answer;
vector<int> v;

void update(int x){
    for(; x <= n; x += x & -x) BIT[x]++;
}

int get(int x){
    int res = 0;
    for(; x; x -= x & -x) res += BIT[x];
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    cin >> n;
    forUp(i, 1, n, 1){
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    forUp(i, 1, n, 1) a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    forDown(i, n, 1, -1){
        answer += get(a[i] - 1);
        update(a[i]);
    }
    cout << answer;

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/nkinv
