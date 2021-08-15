// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        vector<vector<int>> dp=mat;
        int ans=0;
        for(int i=0; i<n; ++i) {
            if(mat[i][0]) ans=1;
            dp[i][0]=mat[i][0];
        }
        for(int j=0; j<m; ++j) {
            if(mat[0][j]) ans=1;
            dp[0][j]=mat[0][j];
        }
        for(int i=1; i<n; ++i) {
            for(int j=1; j<m; ++j) {
                if(mat[i][j]) {
                    dp[i][j]=1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    ans=max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};
