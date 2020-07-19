#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
      int n,m;
      scanf("%d%d", &n,&m);
      char a[n+1], b[m+1];
      scanf("%s%s", &a,&b);
      vector<vector<int>> lcs(n+1, vector<int> (m+1));
      for(int i=1; i<=n; ++i) {
          for(int j=1; j<=m; ++j) {
              lcs[i][j]=(a[i-1]==b[j-1])?(1+lcs[i-1][j-1]):max(lcs[i][j-1], lcs[i-1][j]);
          }
      }
      printf("%d\n", lcs[n][m]);
  }
 
    return 0;
}