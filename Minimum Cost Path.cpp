#include <bits/stdc++.h>
using namespace std;

const int dr[]={-1,0,0,1};
const int dc[]={0,-1,1,0};

bool safe(int r, int c, int n) {
    return r>=0 && c>=0 && r<n && c<n;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<vector<int>> a(n, vector<int>(n)), dist(n, vector<int>(n, 2e9));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        vector<vector<bool>> done(n, vector<bool>(n));
        dist[0][0]=a[0][0];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> p;
        p.push({0,{0,0}});
        while(!p.empty()) {
            pair<int,pair<int,int>> pr=p.top();
            p.pop();
            int d=pr.first, x=pr.second.first, y=pr.second.second;
            if(x==n-1 && y==n-1) break;
            if(dist[x][y]<d) continue;
            done[x][y]=true;
            for(int k=0; k<4; ++k) {
                int r=x+dr[k], c=y+dc[k];
                if(safe(r,c,n) && !done[r][c] && dist[x][y]+a[r][c]<dist[r][c]) {
                    dist[r][c]=dist[x][y]+a[r][c];
                    p.push({dist[r][c], {r,c}});
                }
            }
        }
        printf("%d\n", dist[n-1][n-1]);
    }
    
    return 0;
}
