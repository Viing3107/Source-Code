#include <bits/stdc++.h>
#define N int(1E6+1)
using namespace std;

int Pri[N], C[N];
void sangnt()
{ fill(Pri+1,Pri+N+1,1);
  fill(C+1,C+N+1,1);
  Pri[1]=C[1]=0;
  for(int i=2; i*i<=N; i++)
    if(Pri[i]==1)
      for(int j=i*i; j<=N; j+=i)
        Pri[j]=C[j]=0;
}
int Count(int x)
{ x=int(sqrt(x));
  int ans= 1, i= 2;
  while (i*i <= x)
  { int cnt= 0;
    while (x % i== 0)
    { cnt++;
      x = x/i;
    }
    ans*=2*cnt + 1;
    i++;
  }
  if (x> 1) ans*= 3;
  return ans;
}
void init(){ 
  sangnt();
  for (int i=2; i*i<=N; i++){ 
    int k = Count(i*i);
    if (Pri[k]) C[i*i] = 1;
  }
  for (int i=1; i<=N; i++) C[i]+=C[i-1];
}
int main(){ 
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  freopen("BAI2.INP","r",stdin);
  freopen("BAI2.OUT","w",stdout);
  init();
  int T; cin >> T;
  while (T--){ 
    int a, b;
    cin >> a >> b;
    cout << C[b] - C[a - 1] <<endl;
  }
}
