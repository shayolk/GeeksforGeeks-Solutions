#include <bits/stdc++.h>
using namespace std;

int n,m,e;
vector<int> color;
vector<vector<int>> adj;

bool safe(int now, int c) {
    for(int neb: adj[now]) {
        if(color[neb]==c) {
            return false;
        }
    }
    return true;
}

bool mcol(int now) {
    if(now==n) {
        return true;
    }
    for(int c=0; c<m; ++c) {
        if(safe(now,c)) {
            color[now]=c;
            if(mcol(now+1)) {
                return true;
            }
            color[now]=-1;
        }
    }
    return false;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n,&m,&e);
        adj.clear();
        adj.resize(n);
        for(int i=0; i<e; ++i) {
            int x,y;
            scanf("%d%d", &x,&y);
            adj[--x].push_back(--y);
            adj[y].push_back(x);
        }
        color.clear();
        color.resize(n, -1);
        printf("%d\n", mcol(0));
    }
    
    return 0;
}
