#include <bits/stdc++.h>
using namespace std;

int n,m;
const int dr[]={0,0,-1,-1,-1,1,1,1};
const int dc[]={-1,1,-1,0,1,-1,0,1};

bool safe(int r, int c) {
    return r>=0 && r<n && c>=0 && c<m;
}

void dfs(int i, int j, int& sum, vector<vector<int>>& a, vector<vector<bool>>& vis) {
    vis[i][j]=true;
    ++sum;
    for(int k=0; k<8; ++k) {
        int r=i+dr[k], c=j+dc[k];
        if(safe(r,c) && a[r][c] && !vis[r][c]) {
            dfs(r,c,sum,a,vis);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n,&m);
        vector<vector<int>> a(n, vector<int>(m));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        vector<vector<bool>> vis(n, vector<bool>(m));
        int ans=0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(a[i][j] && !vis[i][j]) {
                    int now=0;
                    dfs(i,j,now,a,vis);
                    ans=max(ans, now);
                }
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
