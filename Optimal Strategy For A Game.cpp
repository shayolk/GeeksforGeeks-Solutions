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
        vector<vector<int>> dp(n, vector<int> (n));
        for(int i=0; i<n; ++i) {
            dp[i][i]=a[i];
            if(i<n-1) {
                dp[i][i+1]=max(a[i], a[i+1]);
            }
        }
        for(int gap=3; gap<n; ++gap) {
            for(int i=0; i+gap<n; ++i) {
                int j=i+gap;
                dp[i][j]=max(a[i]+min(dp[i+2][j], dp[i+1][j-1]), a[j]+min(dp[i][j-2], dp[i+1][j-1]));
            }
        }
        printf("%d\n", dp[0][n-1]);
    }
    
    return 0;
}
