#include <bits/stdc++.h>
using namespace std;

const int nax=1e4+5;
vector<long long> dp(nax, 9e18);

void init() {
    dp[0]=0;
    dp[1]=1;
    for(int i=2; i<nax; ++i) {
        for(int j=1; j*j<=i; ++j) {
            dp[i]=min(dp[i], 1+dp[i-j*j]);
        }
    }
}
 
int main() {
    init();
    int t;
    scanf("%d", &t);
    while(t--) {
      int n;
      scanf("%d", &n);
      printf("%lld\n", dp[n]);
    }

    return 0;
}
