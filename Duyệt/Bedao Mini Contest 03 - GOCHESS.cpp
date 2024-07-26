/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 14:13:34 - 26/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define MASK(i)                 (1ll << (i))
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e2 + 2;
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, k;
vector<int> di[5], dj[5];
pair<int, int> answer[N * N], a[N][N];

bool inside(int x, int y) {return x >= 1 && x <= n && y >= 1 && y <= n;}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> k;
    forUp(i, 1, k, 1) {
        int x, y;
        cin >> x >> y;
        cin >> a[x][y].first;
        a[x][y].second = i;
    }
    // knight
    di[1] = {-2, -2, -1, -1, 1, 1, 2, 2};
    dj[1] = {-1, 1, -2, 2, -2, 2, -1, 1};

    forUp(i, 1, n, 1) {
        // bishop
        di[2].push_back(i);
        dj[2].push_back(i);

        di[2].push_back(-i);
        dj[2].push_back(-i);

        di[2].push_back(-i);
        dj[2].push_back(i);

        di[2].push_back(i);
        dj[2].push_back(-i);

        // rock
        di[3].push_back(i);
        dj[3].push_back(0);
        
        di[3].push_back(0);
        dj[3].push_back(i);

        di[3].push_back(-i);
        dj[3].push_back(0);

        di[3].push_back(0);
        dj[3].push_back(-i);

        // queen
        di[4].push_back(i);
        dj[4].push_back(0);
        
        di[4].push_back(0);
        dj[4].push_back(i);

        di[4].push_back(-i);
        dj[4].push_back(0);

        di[4].push_back(0);
        dj[4].push_back(-i);

        di[4].push_back(i);
        dj[4].push_back(i);

        di[4].push_back(-i);
        dj[4].push_back(-i);

        di[4].push_back(-i);
        dj[4].push_back(i);

        di[4].push_back(i);
        dj[4].push_back(-i);
    }
    forUp(i, 1, n, 1) forUp(j, 1, n, 1) {
        if (a[i][j].first) {
            forUp(l, 0, di[a[i][j].first].size() - 1, 1) {
                int i1 = i + di[a[i][j].first][l];
                int j1 = j + dj[a[i][j].first][l];
                if (inside(i1, j1) && a[i1][j1].first) {
                    answer[a[i][j].second].first++;
                    answer[a[i1][j1].second].second++;
                }
            }    
        }
    }
    forUp(i, 1, k, 1) cout << answer[i].first << " " << answer[i].second << endl;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bedao_m03_gochess