//User function template for C++

class Solution{   
public:
    bool isSubsetSum(int n, int arr[], int sum){
        int tot=0;
        for(int i=0; i<n; ++i) tot+=arr[i];
        if(tot<sum) return false;
        int ans=false;
        vector<vector<bool>> dp(n+1, vector<bool> (tot+1));
        for(int i=0; i<=n; ++i) {
            dp[i][0]=true;
        }
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=tot; ++j) {
                dp[i][j]=dp[i-1][j];
                if(j-arr[i-1]>=0) {
                    dp[i][j]=dp[i][j] || dp[i-1][j-arr[i-1]];
                }
                if(j==sum) ans=ans || dp[i][j];
            }
        }
        return ans;
    }
};
