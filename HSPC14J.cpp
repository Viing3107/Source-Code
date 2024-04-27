# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 1e3 + 3;
bool mark[N];
int n, k, ans;

int calc(int n, int k){
	int res = 0;
	for (int i = 2; i <= n; i++)
		if (mark[i])
			for (int j = i; j <= n; j += i)
				if (mark[j]){
					mark[j] = false;
					res++;
					if (res == k) return j;
				}
}

int main(){      

	while (cin >> n >> k){
		memset(mark, true, sizeof mark);
		cout << calc(n, k) << endl;
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/hspc14j
