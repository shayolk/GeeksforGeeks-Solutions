/*You are required to complete this method*/
int wildCard(string pattern,string s) {
    string p;
    int i=0, n=(int)pattern.size(), m=(int)s.size();
    while(i<n) {
        int flag=false;
        while(i<n && pattern[i]=='*') {
            flag=true;
            ++i;
        }
        if(flag) {
            p+='*';
        }
        if(i<n) {
            p+=pattern[i++];
        }
    }
    n=p.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    dp[0][0]=1;
    for(int i=1; i<=n; ++i) {
        if(p[i-1]=='*') {
            dp[i][0]=dp[i-1][0];
        }
    }
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(p[i-1]==s[j-1] || p[i-1]=='?') {
                dp[i][j]=dp[i-1][j-1];
            }
            else if(p[i-1]=='*') {
                if(j==1) {
                    dp[i][j]=dp[i-1][j-1] || dp[i-1][j];
                }
                else if(i==1) {
                    dp[i][j]=1;
                }
                else {
                    dp[i][j]=dp[i][j-1] || dp[i-1][j-1] || dp[i-1][j];
                }
            }
            else {
                dp[i][j]=0;
            }
        }
    }
    return dp[n][m];
}
