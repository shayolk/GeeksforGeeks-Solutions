class Solution{

	public:
	int minPoints(vector<vector<int>> points, int M, int N) 
	{
	    vector<vector<int>> dp(M, vector<int> (N));
	    dp[M-1][N-1]=max(1, 1-points[M-1][N-1]);
	    for(int i=M-2; i>=0; --i) {
	        dp[i][N-1]=max(1, dp[i+1][N-1]-points[i][N-1]);
	    }
	    for(int j=N-2; j>=0; --j) {
	        dp[M-1][j]=max(1, dp[M-1][j+1]-points[M-1][j]);
	    }
	    for(int i=M-2; i>=0; --i) {
	        for(int j=N-2; j>=0; --j) {
	            dp[i][j]=max(1, min(dp[i+1][j], dp[i][j+1])-points[i][j]);
	        }
	    }
	    return dp[0][0];
	} 
};
