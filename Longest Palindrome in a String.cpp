class Solution {
  public:
    string longestPalin (string S) {
        int n=S.size(), ind=0, len=1;
        vector<vector<bool>> dp(n, vector<bool> (n));
        for(int i=0; i<n; ++i) {
            dp[i][i]=true;
            if(i && S[i-1]==S[i]) {
                dp[i-1][i]=true;
                if(len<2) {
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
