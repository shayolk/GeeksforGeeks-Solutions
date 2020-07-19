#include <bits/stdc++.h>
using namespace std;

const long long mod=1e9+7, nax=1e3+5;
vector<long long> fact(nax, 1);

// long long modex(long long x, long long p) {
//     if(x==0) {
//         return 0;
//     }
//     x%=mod;
//     long long res=1;
//     while(p) {
//         if(p&1) {
//             res=(res*x)%mod;
//         }
//         x=(x*x)%mod;
//         p/=2;
//     }
//     return res;
// }
 
int main() {
//  for(int i=2; i<nax; ++i) {
//      fact[i]=(i*fact[i-1])%mod;
//  }
//  int t;
//  scanf("%d", &t);
//  while(t--) {
//      int n,r;
//      scanf("%d%d", &n,&r);
//      // long long ans=fact[n]/(fact[n-r]*fact[r]);
//      long long ans=(fact[n]*modex((fact[n-r]*fact[r])%mod,mod-2))%mod;
//      printf("%lld\n", ans);
//  }

    vector<vector<int>> dp(nax, vector<int> (nax));
    for(int i=1; i<nax; ++i) {
        dp[i][0]=dp[i][i]=1;
        for(int j=1; j<i; ++j) {
            dp[i][j]=(dp[i-1][j-1] + dp[i-1][j])%mod;
        }
    }
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,r;
        scanf("%d%d", &n,&r);
        printf("%d\n", dp[n][r]);
    }
 
    return 0;
}