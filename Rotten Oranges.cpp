#include <bits/stdc++.h>
using namespace std;

int n,m;
int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};

bool safe(int r, int c) {
    return r>=0 && r<n && c>=0 && c<m;
}

void bfs(vector<vector<int>>& a, queue<pair<int,int>>& q, int& ans) {
    while(!q.empty()) {
        ++ans;
        while(q.front().first!=-1) {
            pair<int,int> p=q.front();
            q.pop();
            for(int i=0; i<4; ++i) {
                int r=p.first+dr[i], c=p.second+dc[i];
                if(safe(r,c) && a[r][c]==1) {
                    a[r][c]=2;
                    q.push({r,c});
                }
            }
        }
        q.pop();
        if(!q.empty()) q.push({-1,-1});
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n,&m);
        vector<vector<int>> a(n, vector<int> (m));
        queue<pair<int,int>> q;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                scanf("%d", &a[i][j]);
                if(a[i][j]==2) q.push({i,j});
            }
        }
        q.push({-1,-1});
        int ans=0;
        bfs(a,q,ans);
        --ans;
        bool flag=false;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(a[i][j]==1) {
                    ans=-1;
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
