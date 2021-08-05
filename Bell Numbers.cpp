class Solution{
    const int mod=1e9+7;
    
public:
    int bellNumber(int n)
    {
        vector<vector<int>> bell(n+1, vector<int> (n+1));
        bell[1][1]=1;
        for(int i=2; i<=n; ++i) {
            bell[i][1]=bell[i-1][i-1];
            for(int j=2; j<=i; ++j) {
                bell[i][j]=(bell[i][j-1]+bell[i-1][j-1])%mod;
            }
        }
        return bell[n][n];
    }
};
