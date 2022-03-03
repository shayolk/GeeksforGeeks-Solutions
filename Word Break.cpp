//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        int n=A.size();
        vector<bool> dp(n+1);
        dp[0]=true;
        for(int i=1; i<=n; ++i) {
            for(string s: B) {
                int m=s.size();
                if(i-m>=0 && dp[i-m] && A.substr(i-m, m)==s) {
                    dp[i]=true;
                }
            }
        }
        return dp[n];
    }
};
