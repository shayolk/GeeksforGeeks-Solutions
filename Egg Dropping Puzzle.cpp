#include <bits/stdc++.h>
using namespace std;
 
// int egg(int n, int k) {
//     if(n==1 || k<=1) {
//         return k;
//     }
//     int res=9e9;
//     for(int x=1; x<=k; ++x) {
//         res=min(res,1+max(egg(n-1,x-1), egg(n,k-x)));
//     }
//     return res;
// }
 
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,k;
        scanf("%d%d", &n,&k);
       // printf("%d\n", egg(n,k));
       vector<vector<int>> dp(n+1, vector<int> (k+1));
       for(int j=1; j<=k; ++j) {
           dp[1][j]=j;
       }
       for(int i=1; i<=n; ++i) {
           dp[i][1]=1;
       }
       for(int i=2; i<=n; ++i) {
           for(int j=2; j<=k; ++j) {
               dp[i][j]=2e9;
               for(int x=1; x<=j; ++x) {
                   dp[i][j]=min(dp[i][j], 1+max(dp[i-1][x-1], dp[i][j-x]));
               }
           }
       }
       printf("%d\n", dp[n][k]);
    }
 
    return 0;
}