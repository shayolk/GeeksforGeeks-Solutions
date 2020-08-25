#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        string s;
        cin>>s;
        int n=(int)s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        int lcs=1;
        for(int gap=1; gap<n; ++gap) {
            for(int i=0; i+gap<n; ++i) {
                int j=i+gap;
                if(s[i]==s[j]) {
                    dp[i][j]=dp[i+1][j-1];
                }
                else {
                    dp[i][j]=1+min(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        printf("%d\n", dp[0][n-1]);
    }
    
    return 0;
}
