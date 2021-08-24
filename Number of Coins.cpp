class Solution{
    const int INF=1e9+5;

	public:
	int minCoins(int coins[], int M, int V) 
	{
	    vector<int> dp(V+1, INF);
	    dp[0]=0;
	    for(int i=1; i<=V; ++i) {
	        for(int j=0; j<M; ++j) {
	            if(i-coins[j]>=0) {
	                dp[i]=min(dp[i], 1+dp[i-coins[j]]);
	            }
	        }
	    }
	    if(dp[V]>=INF) return -1;
	    return dp[V];
	} 
	  
};
