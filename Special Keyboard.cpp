// User function Template for C++

class Solution{
public:
    long long int optimalKeys(int N){
        long long dp[N+1];
        for(int i=1; i<=6; ++i) {
            dp[i]=i;
            if(i==N) return dp[N];
        }
        for(int i=7; i<=N; ++i) {
            dp[i]=max({1+dp[i-1], 2*dp[i-3], 3*dp[i-4], 4*dp[i-5]});
        }
        return dp[N];
    }
};
