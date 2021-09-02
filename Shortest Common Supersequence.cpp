//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        vector<vector<int>> lcs(m+1, vector<int> (n+1));
        for(int i=1; i<=m; ++i) {
            for(int j=1; j<=n; ++j) {
                lcs[i][j]=max({lcs[i][j-1], lcs[i-1][j], (X[i-1]==Y[j-1])+lcs[i-1][j-1]});
            }
        }
        return m+n-lcs[m][n];
    }
};
