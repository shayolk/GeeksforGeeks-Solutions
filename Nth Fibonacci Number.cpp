#include <bits/stdc++.h>
using namespace std;
 
const int M=1e9+7;
 
int main() {
  vector<int> fib(1001, 1);
  for(int i=3; i<=1000; ++i) {
      fib[i]=(fib[i-1]+fib[i-2])%M;
  }
  int t;
  scanf("%d", &t);
  while(t--) {
      int n;
      scanf("%d", &n);
      printf("%d\n", fib[n]);
  }

    return 0;
}
