#include <bits/stdc++.h>
using namespace std;

const int dr[]={-1,0,0,1};
const int dc[]={0,-1,1,0};

bool safe(int r, int c, int n) {
    return r>=0 && r<n && c>=0 && c<n;
}

bool bfs(int x, int y, int n, vector<vector<int>>& a) {
    vector<vector<bool>> vis(n, vector<bool> (n));
    vis[x][y]=true;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()) {
        pair<int,int> p=q.front();
        q.pop();
        for(int i=0; i<4; ++i) {
            int r=p.first+dr[i], c=p.second+dc[i];
            if(safe(r,c,n) && a[r][c] && !vis[r][c]) {
                if(a[r][c]==2) return true;
                vis[r][c]=true;
                q.push({r,c});
            }
        }
    }
    return false;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<vector<int>> a(n, vector<int>(n));
        int x=-1, y=-1;
        bool two=false;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                scanf("%d", &a[i][j]);
                if(a[i][j]==1) {
                    x=i;
                    y=j;
                }
                if(a[i][j]==2) {
                    two=true;
                }
            }
        }
        if(x==-1 || !two) {
            printf("0\n");
            continue;
        }
        printf("%d\n", bfs(x,y,n,a));
    }
    
    return 0;
}
