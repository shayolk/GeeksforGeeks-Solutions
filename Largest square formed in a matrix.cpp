#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        scanf("%d%d", &n,&m);
        vector<vector<int>> a(n, vector<int> (m)), dp(n, vector<int> (m));
        int ans=0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                scanf("%d", &a[i][j]);
                if(!i || !j) {
                    dp[i][j]=a[i][j];
                }
                if(a[i][j]) {
                    ans=1;
                }
            }
        }
        for(int i=1; i<n; ++i) {
            for(int j=1; j<m; ++j) {
                if(a[i][j]) {
                    dp[i][j]=1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    ans=max(ans, dp[i][j]);
                }
            }
        }
        printf("%d\n", ans);
    }
 
    return 0;
}