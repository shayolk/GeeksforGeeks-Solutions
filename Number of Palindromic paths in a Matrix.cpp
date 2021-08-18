//User function template for C++

class Solution {
    int n,m;
    const int M=1e9+7;
    map<tuple<int,int,int,int>,int> dp;
    
    bool safe(int i, int j) {
        return i>=0 && i<n && j>=0 && j<m;
    }
    
    int dfs(int lr, int lc, int rr, int rc, vector<vector<char>>& matrix) {
        if(!safe(lr, lc) || !safe(rr, rc)) return 0;
        if(lr>rr || lc>rc) return 0;
        // printf("%d %d %d %d\n", lr,lc,rr,rc);
        if(dp.count(make_tuple(lr, lc, rr, rc))) return dp[make_tuple(lr, lc, rr, rc)];
        if(matrix[lr][lc]!=matrix[rr][rc]) return 0;
        if(rr-lr+rc-lc<=1) return 1;
        int ans=0;
        ans=(ans+dfs(lr+1, lc, rr-1, rc, matrix))%M;
        ans=(ans+dfs(lr+1, lc, rr, rc-1, matrix))%M;
        ans=(ans+dfs(lr, lc+1, rr-1, rc, matrix))%M;
        ans=(ans+dfs(lr, lc+1, rr, rc-1, matrix))%M;
        return dp[make_tuple(lr, lc, rr, rc)]=ans;
    }
    
  public:
    int countPalindromicPaths(vector<vector<char>>matrix){
        n=matrix.size(), m=matrix[0].size();
        return dfs(0, 0, n-1, m-1, matrix);
    }
};
