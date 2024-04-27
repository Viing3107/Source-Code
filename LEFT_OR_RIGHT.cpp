# include <bits/stdc++.h>
# define ll long long
# define endl "\n"

using namespace std;

ll t, m, n, res, temp;
stack<char> st;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	while (t--){
		cin >> n;
		while (n != 1){
			if (n % 2) st.push('R');
			else st.push('L');
			n /= 2;
		}
		while (!st.empty()){
			cout << st.top();
			st.pop();
		}
		cout << endl;
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/icpc21_regional_l
