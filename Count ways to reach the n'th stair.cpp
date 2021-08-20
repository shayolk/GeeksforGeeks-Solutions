class Solution
{
    const int M=1e9+7;
    
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        vector<long long> dp(n+1);
        dp[0]=1;
        for(int i=0; i<n; ++i) {
            if(dp[i]) {
                if(i+1<=n) dp[i+1]=(dp[i+1]+dp[i])%M;
                if(i+2<=n) dp[i+2]=(dp[i+2]+dp[i])%M;
            }
        }
        return dp[n];
    }
};
