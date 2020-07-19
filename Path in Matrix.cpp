#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<vector<long long>> dp(n+1, vector<long long> (n+2));
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                scanf("%lld", &dp[i][j]);
            }
        }
        for(int i=2; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                dp[i][j]+=max({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]});
            }
        }
        long long ans=0;
        for(int j=1; j<=n; ++j) {
            ans=max(ans, dp[n][j]);
        }
        printf("%lld\n", ans);
    }
 
    return 0;
}