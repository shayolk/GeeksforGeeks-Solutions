#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for(int& i:a) {
            scanf("%d", &i);
        }
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][1]=a[0];
        for(int i=1; i<n; ++i) {
            dp[i][0]=max(dp[i-1][0], dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+a[i];
        }
        printf("%d\n", max(dp[n-1][0], dp[n-1][1]));
    }
    
    return 0;
}
