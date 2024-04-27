# include <bits/stdc++.h>
# define ll long long

using namespace std;

ll t, l, r, temp;

void calc(int y){
	cin >> l >> r;
	for (int i = 39; i >= 1; i--){
		temp = 2;
		while (pow(temp, i) <= r) temp++;
		if (pow(temp - 1, i) >= l && temp > 2){
			cout << "Case #" << y << ": " << i << endl;
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	for (int i = 1; i <= t; i++) calc(i);
	return 0;
}

// https://oj.vnoi.info/problem/power
