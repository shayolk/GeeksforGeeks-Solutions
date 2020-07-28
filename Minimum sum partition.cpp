#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, sum=0;
        scanf("%d", &n);
        vector<int> a(n);
        for(int& i: a) {
            scanf("%d", &i);
            sum+=i;
        }
        // vector<vector<bool>> dp(sum+1, vector<bool> (n+1));
        bool dp[sum+1][n+1];
        for(int i=1; i<=sum; ++i) {
            dp[i][0]=false;
        }
        for(int j=0; j<=n; ++j) {
            dp[0][j]=true;
        }
        for(int i=1; i<=sum; ++i) {
            for(int j=1; j<=n; ++j) {
                dp[i][j]=dp[i][j-1];
                if(i-a[j-1]>=0) {
                    dp[i][j]=dp[i][j] || dp[i-a[j-1]][j-1];
                }
            }
        }
        int dif=2e9;
        for(int i=sum/2; i>=0; --i) {
            if(dp[i][n]) {
                dif=sum-2*i;
                break;
            }
        }
        printf("%d\n", dif);
        // sort(a.rbegin(), a.rend());
        // int s=0, d=0;
        // for(int i: a) {
        //     if(s<=d) {
        //         s+=i;
        //     }
        //     else {
        //         d+=i;
        //     }
        // }
        // printf("%d\n", abs(s-d));
    }
    
    return 0;
}
