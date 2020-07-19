#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
      int n;
      scanf("%d", &n);
      int mx=-2e9, so=0, x;
      for(int i=0; i<n; ++i) {
          scanf("%d", &x);
          so=max(x, so+x);
          mx=max(mx, so);
      }
      printf("%d\n", mx);
  }
 
    return 0;
}