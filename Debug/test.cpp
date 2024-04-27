#include <bits/stdc++.h>
#define int long long
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define forEach(it, v) for(typeof(v.begin()) it = v.begin(), _e = v.end(); it != _e; it++)

using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 500;
int n;

int Rd(int l, int r){
    return l + (rd() * rd() % (r - l + 1) + (r - l + 1)) % (r - l + 1);
}

void make_test(){
	ofstream cout ("test.inp");
    int n = Rd(5, 10);
    cout << n << endl;
    forUp(i, 1, n, 1) cout << Rd(1, 10) << " ";
    cout.close();
}

signed main(){
    srand(time(0));
    make_test();
    // forUp(i, 1, N, 1){
    //     make_test();
    //     system("BF.exe");
    //     system("AC.exe");
    //     if (system("fc test.out test.ans")) return (0 ^ 0);
    // }
    
    return 0;
}