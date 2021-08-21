class Solution{
    vector<vector<char>> key={
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
        {'*', '0', '#'}
    };
    
    const int dr[5]={0, 0, 0, -1, 1};
    const int dc[5]={0, -1, 1, 0, 0};
    long long dp[10][30];
    
    bool ok(int i, int j) {
        return i>=0 && i<4 && j>=0 && j<3 && key[i][j]!='*' && key[i][j]!='#';
    }

	public:
	long long getCount(int N)
	{
	    for(int i=0; i<10; ++i) {
	        dp[i][1]=1;
	    }
	    for(int i=0; i<4; ++i) {
	        for(int j=0; j<3; ++j) {
	            if(!ok(i, j)) continue;
	            int now=key[i][j]-'0';
	            for(int k=2; k<=N; ++k) {
	                dp[now][k]=0;
	                for(int d=0; d<5; ++d) {
	                    int r=i+dr[d], c=j+dc[d];
	                    if(ok(r, c)) {
	                        dp[now][k]+=dp[key[r][c]-'0'][k-1];
	                    }
	                }
	            }
	        }
	    }
	    long long ans=0;
	    for(int i=0; i<10; ++i) {
	        ans+=dp[i][N];
	    }
	    return ans;
	}


};
