class Solution
{
    int n,m,lcs;
    set<string> ans;
    
    void find(int i, int j, string now, string& s, string& t, vector<vector<int>>& dp) {
        // cout<<now<<"\n";
        if(now.size()==lcs) {
            reverse(now.begin(), now.end());
            ans.insert(now);
            return;
        }
        if(i==0 || j==0) {
            return;
        }
        for(char c='a'; c<='z'; ++c) {
            for(int ii=i-1; ii>=0; --ii) {
                if(s[ii]==c) {
                    for(int jj=j-1; jj>=0; --jj) {
                        if(t[jj]==c && dp[ii+1][jj+1]==lcs-now.size()) {
                            find(ii, jj, now+c, s, t, dp);
                        }
                    }
                }
            }
        }
    }
    
	public:
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    n=s.size();
		    m=t.size();
		    vector<vector<int>> dp(n+1, vector<int> (m+1));
		    for(int i=1; i<=n; ++i) {
		        for(int j=1; j<=m; ++j) {
		            dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		            if(s[i-1]==t[j-1]) {
		                dp[i][j]=max(dp[i][j], 1+dp[i-1][j-1]);
		            }
		        }
		    }
		    lcs=dp[n][m];
		    find(n, m, "", s, t, dp);
		    vector<string> ret(ans.begin(), ans.end());
		    return ret;
		}
};
