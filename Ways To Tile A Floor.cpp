class Solution {
    const int M=1e9+7;
    
  public:
    long long numberOfWays(long long N) {
        long long dp[N+1];
        dp[0]=dp[1]=1;
        for(int i=2; i<=N; ++i) {
            dp[i]=(dp[i-1]+dp[i-2])%M;
        }
        return dp[N];
    }
};
