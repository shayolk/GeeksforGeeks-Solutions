/*You are required to complete this method*/

class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> dp(m);
        int ans=0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(M[i][j]) dp[j]+=1;
                else dp[j]=0;
            }
            int h, ls, rs;
            stack<int> s;
            for(int j=0; j<=m; ++j) {
                while(!s.empty() && (j==m || dp[j]<=dp[s.top()])) {
                    h=dp[s.top()];
                    s.pop();
                    ls=s.empty()?-1:s.top();
                    rs=j;
                    ans=max(ans, h*(rs-ls-1));
                }
                s.push(j);
            }
        }
        return ans;
    }
};
