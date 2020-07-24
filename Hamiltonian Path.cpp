#include <bits/stdc++.h>
using namespace std;

bool dfs(int start, int now, int cnt, int n, vector<vector<int>> adj, vector<bool> vis) {
    if(cnt==n) {
        /* For Hamiltonian Cycle */
        // if(count(adj[now].begin(), adj[now].end(), start)) return true;
        // else return false;
        return true;
    }
    vis[now]=true;
    for(int neb: adj[now]) {
        if(!vis[neb]) {
            if(dfs(start,neb,cnt+1,n,adj,vis)) return true;
        }
    }
    return false;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        scanf("%d%d", &n,&m);
        vector<vector<int>> adj(n);
        for(int i=0; i<m; ++i) {
            int u,v;
            scanf("%d%d", &u,&v);
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        vector<bool> vis(n);
        bool ham=false;
        for(int i=0; i<n; ++i) {
            if(dfs(i,i,1,n,adj,vis)) {
                ham=true;
                break;
            }
        }
        printf("%d\n", ham);
    }
    
    return 0;
}
