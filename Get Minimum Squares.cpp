//User function Template for C++

class Solution{
	public:
	int MinSquares(int n)
	{
	    vector<int> dp(n+1, 1e9+5);
	    dp[0]=0;
	    dp[1]=1;
	    for(int i=2; i<=n; ++i) {
	        for(int j=1; j*j<=i; ++j) {
	            dp[i]=min(dp[i], 1+dp[i-j*j]);
	        }
	    }
	    return dp[n];
	}
};
