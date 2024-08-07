/*
	Author : Do Quang Vinh
	Kim Son A High School - Ninh Binh
	Created : 18:21:56 - 02/07/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for(int i = (l); i >= (r); i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e6 + 6;
const int M 	= 30;
const int INF   = 0x3f3f3f3f3f3f3f3f;

string s, t;
int cntT[M], cnt[N][M], n, m, result;

bool check(int l, int r){
	forUp (i, 1, 26, 1) {
		if (cnt[r][i] - cnt[l - 1][i] != cntT[i]) return false;
	}
	return true;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

	cin >> s >> t;
	n = s.size();
	m = t.size();
	s = " " + s;
	t = " " + t;
	forUp (i, 1, n, 1) {
		forUp (j, 1, 26, 1) cnt[i][j] = cnt[i - 1][j];
		cnt[i][s[i] - 'a' + 1]++;
	}
	forUp (i, 1, m, 1) cntT[t[i] - 'a' + 1]++;
	forUp (i, 1, n - m + 1, 1) result += check(i, i + m - 1);
	cout << result;
	
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

	return (0 ^ 0);
}

/*

	/\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb054_strcnt