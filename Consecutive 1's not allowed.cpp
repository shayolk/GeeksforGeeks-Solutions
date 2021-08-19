//User function template for C++
class Solution{
    const int M=1e9+7;
public:
	// #define ll long long
	ll countStrings(int n) {
	    ll dp[n+1][2];
	    dp[0][0]=1;
	    dp[0][1]=0;
	    for(int i=1; i<=n; ++i) {
	        dp[i][0]=(dp[i-1][0]+dp[i-1][1])%M;
	        dp[i][1]=dp[i-1][0];
	    }
	    return (dp[n][0]+dp[n][1])%M;
	}
};
