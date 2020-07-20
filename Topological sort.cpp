// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/

void dfs(int now, vector<int> adj[], vector<bool>& vis, vector<int>& ret) {
    vis[now]=true;
    for(int neb: adj[now]) {
        if(!vis[neb]) {
            dfs(neb, adj, vis, ret);
        }
    }
    ret.emplace_back(now);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    stack<int> s;
    vector<bool> vis(V);
    static vector<int> ret;
    for(int i=0; i<V; ++i) {
        if(!vis[i]) {
            dfs(i, adj, vis, ret);
        }
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
