#include <bits/stdc++.h>
using namespace std;

const int dr[]={-1,0,0,1};
const int dc[]={0,-1,1,0};

struct A {
    int i,j,d;
};

bool safe(int r, int c, int n, int m) {
    return r>=0 && r<n && c>=0 && c<m;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        scanf("%d%d", &n,&m);
        vector<vector<int>> ar(n, vector<int>(m));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                scanf("%d", &ar[i][j]);
            }
        }
        int x,y;
        scanf("%d%d", &x,&y);
        vector<vector<bool>> vis(n, vector<bool>(m));
        stack<A> s;
        if(ar[0][0]) s.push({0,0,0});
        int ans=2e9;
        while(!s.empty()) {
            A a=s.top();
            s.pop();
            vis[a.i][a.j]=true;
            if(a.i==x && a.j==y) {
                ans=min(ans, a.d);
            }
            for(int k=0; k<4; ++k) {
                int r=a.i+dr[k], c=a.j+dc[k];
                if(safe(r,c,n,m) && ar[r][c] && !vis[r][c]) {
                    s.push({r,c,a.d+1});
                }
            }
        }
        printf("%d\n", ans==2e9?-1:ans);
    }
    
    return 0;
}
