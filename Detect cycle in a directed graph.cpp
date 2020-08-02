/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool dfs(int now, vector<bool>& vis, vector<int> adj[], vector<bool>& rec) {
    rec[now]=true;
    vis[now]=true;
    for(int neb: adj[now]) {
        if(!vis[neb] && dfs(neb,vis,adj,rec)) return true;
        if(rec[neb]) return true;
    }
    rec[now]=false;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> vis(V), rec(V);
    for(int i=0; i<V; ++i) {
        if(!vis[i]) {
            if(dfs(i,vis,adj,rec)) return true;
        }
    }
    return false;
}
