// User function Template for C++

class Solution{
public:
    int palindromicPartition(string s)
    {
        int n=s.size();
        vector<vector<bool>> pal(n+1, vector<bool> (n+1));
        for(int i=1; i<=n; ++i) {
            pal[i][i]=true;
            if(i>1 && s[i-2]==s[i-1]) pal[i-1][i]=true;
        }
        for(int gap=2; gap<n; ++gap) {
            for(int i=1; i+gap<=n; ++i) {
                int j=i+gap;
                pal[i][j]=s[i-1]==s[j-1] && pal[i+1][j-1];
            }
        }
        vector<int> dp(n+1);
        dp[0]=dp[1]=0;
        for(int i=2; i<=n; ++i) {
            if(pal[1][i]) continue;
            dp[i]=i-1;
            for(int j=1; j<=i; ++j) {
                if(pal[j][i]) {
                    dp[i]=min(dp[i], 1+dp[j-1]);
                }
            }
        }
        return dp[n];
    }
};
