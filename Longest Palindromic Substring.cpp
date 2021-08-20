//User function template for C++

class Solution{   
public:
    string longestPalindrome(string S){
        int n=S.size();
        vector<vector<bool>> dp(n, vector<bool> (n));
        int len=1, ind=0;
        for(int i=0; i<n; ++i) {
            dp[i][i]=true;
            if(i && S[i-1]==S[i]) {
                dp[i-1][i]=true;
                if(len==1) {
                    len=2;
                    ind=i-1;
                }
            }
        }
        for(int gap=2; gap<n; ++gap) {
            for(int i=0; i+gap<n; ++i) {
                int j=i+gap;
                if(S[i]==S[j] && dp[i+1][j-1]) {
                    dp[i][j]=true;
                    if(len<gap+1) {
                        len=gap+1;
                        ind=i;
                    }
                }
            }
        }
        return S.substr(ind, len);
    }
};
