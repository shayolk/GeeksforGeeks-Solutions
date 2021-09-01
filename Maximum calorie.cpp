class Solution{
	public:
	int maxCalories(int arr[], int n)
	{
	    if(n<=2) {
	        return accumulate(arr, arr+n, 0);
	    }
	    int dp[n][2];
	    dp[0][0]=0;
	    dp[0][1]=arr[0];
	    dp[1][0]=arr[0];
	    dp[1][1]=arr[0]+arr[1];
	    for(int i=2; i<n; ++i) {
	        dp[i][0]=max(dp[i-1][0], dp[i-1][1]);
	        dp[i][1]=arr[i]+max(dp[i-1][0], dp[i-2][0]+arr[i-1]);
	    }
	    return max(dp[n-1][0], dp[n-1][1]);
	}
};
