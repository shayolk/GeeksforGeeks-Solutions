#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int m;
        scanf("%d", &m);
        vector<int> a(m);
        for(int& i: a) {
            scanf("%d", &i);
        }
        int n=m-1;
        vector<vector<long long>> dp(n+1, vector<long long> (n+1, 0LL));
        for(int gap=1; gap<n; ++gap) {
            for(int i=1; i+gap<=n; ++i) {
                int j=i+gap;
                dp[i][j]=9e18;
                for(int k=i; k<j; ++k) {
                    long long his=dp[i][k]+dp[k+1][j]+1LL*a[i-1]*a[k]*a[j];
                    dp[i][j]=min(dp[i][j], his);
                }
            }
        }
        printf("%lld\n", dp[1][n]);
    }
 
    return 0;
}