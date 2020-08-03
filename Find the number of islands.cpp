/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
const int dr[]={-1,-1,-1,0,0,1,1,1};
const int dc[]={-1,0,1,-1,1,-1,0,1};

bool safe(int r, int c, int n, int m) {
    return r>=0 && r<n && c>=0 && c<m;
}

int dfs(int i, int j, int n, int m, vector<int> A[], vector<vector<bool>>& vis) {
    vis[i][j]=true;
    int cnt=1;
    for(int k=0; k<8; ++k) {
        int r=i+dr[k], c=j+dc[k];
        if(safe(r,c,n,m) && A[r][c] && !vis[r][c]) {
            cnt+=dfs(r,c,n,m,A,vis);
        }
    }
    return cnt;
}

int findIslands(vector<int> A[], int N, int M) {
    vector<vector<bool>> vis(N, vector<bool>(M));
    int ans=0;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            if(A[i][j] && !vis[i][j]) {
                int now=dfs(i,j,N,M,A,vis);
                ans+=now>=1;
            }
        }
    }
    return ans;
}
