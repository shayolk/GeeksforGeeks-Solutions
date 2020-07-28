#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int k,n;
        scanf("%d%d", &k,&n);
        vector<int> a(n), pref={0};
        for(int& i: a) {
            scanf("%d", &i);
            pref.push_back(pref.back()+i);
        }
        vector<vector<int>> dp(k+1, vector<int> (n+1));
        for(int j=1; j<=n; ++j) {
        	dp[1][j]=pref[j];
        }
        for(int i=2; i<=k; ++i) {
            for(int j=1; j<=n; ++j) {
                dp[i][j]=2e9;
                for(int l=0; l<=j; ++l) {
                    dp[i][j]=min(dp[i][j], max(dp[i-1][l], pref[j]-pref[l]));
                }
            }
        }
        printf("%d\n", dp[k][n]);
    }
    
    return 0;
}
