class Solution{
    const int M=1e9+7;
    
	public:
	int TotalWays(int N)
	{
	    long long dp[N+1][2];
	    dp[0][0]=1;
	    dp[0][1]=0;
	    for(int i=1; i<=N; ++i) {
	        dp[i][0]=(dp[i-1][0]+dp[i-1][1])%M;
	        dp[i][1]=dp[i-1][0];
	    }
	    long long ans=(dp[N][0]+dp[N][1])%M;
	    return (ans*ans)%M;
	}
};
