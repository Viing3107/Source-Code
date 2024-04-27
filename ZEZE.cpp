# include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int m;
	cin >> m;
	int a = 0;
	int b = 0;
	while (m--){
		int n;
		cin >> n;
		while (n % 2 == 0){
			a++;
			n /= 2;
		}
		while (n % 5 == 0){
			b++;
			n /= 5;
		}
	}
	cout << min(a, b) << endl;
	
	return 0;
}

// https://oj.vnoi.info/problem/bedao_g04_zeze
