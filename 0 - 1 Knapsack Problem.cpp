#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n,c;
        scanf("%d%d", &n,&c);
        vector<int> v(n), w(n);
        for(int& i: v) {
            scanf("%d", &i);
        }
        for(int& i: w) {
            scanf("%d", &i);
        }
        vector<vector<int>> dp(n+1, vector<int> (c+1,0));
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=c; ++j) {
                if(w[i-1]>j) {
                    dp[i][j]=dp[i-1][j];
                }
                else {
                    dp[i][j]=max(dp[i-1][j], v[i-1]+dp[i-1][j-w[i-1]]);
                }
            }
        }
        printf("%d\n", dp[n][c]);
    }
 
    return 0;
}
