#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for(int i=0; i<n; ++i) {
            scanf("%d", &a[i]);
        }
        vector<int> dp(n, 2e9);
        dp[0]=0;
        for(int i=0; i<n-1; ++i) {
            for(int j=1; j<=a[i] && i+j<n; ++j) {
                dp[i+j]=min(dp[i+j], 1+dp[i]);
            }
        }
        if(dp[n-1]==2e9) {
            printf("-1\n");
            continue;
        }
        printf("%d\n", dp[n-1]);
    }
 
    return 0;
}