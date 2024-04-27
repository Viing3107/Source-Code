# include <bits/stdc++.h>
# define int long long

using namespace std;

int n, k;
stack<char> st;
deque<char> q;
string s;
char x;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '<'){
			if (!q.empty()){
				x = q.back();
				q.pop_back();
				st.push(x);
			}
		}
		else if (s[i] == '>'){
			if (!st.empty()){
				x = st.top();
				st.pop();
				q.push_back(x);
			}
		}
		else if (s[i] != '-') q.push_back(s[i]);
		else if (!q.empty()) q.pop_back();
	}
	while (!q.empty()){
		cout << q.front();
		q.pop_front();
	}
	while (!st.empty()){
		cout << st.top();
		st.pop();
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/fc035_keylogger
