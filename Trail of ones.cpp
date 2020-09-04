#include <bits/stdc++.h>
using namespace std;

int main() {
    int dp[31][2];
    dp[1][0]=dp[1][1]=1;
    for(int i=2; i<31; ++i) {
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
    }
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", (1<<n)-dp[n][0]-dp[n][1]);
    }
    
    return 0;
}
