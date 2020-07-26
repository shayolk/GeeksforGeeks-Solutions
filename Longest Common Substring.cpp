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
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        int sz=0;
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                if(a[i-1]==b[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                    sz=max(sz, dp[i][j]);
                }
            }
        }
        printf("%d\n", sz);
    }
    
    return 0;
}
