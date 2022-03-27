class Solution {
    vector<bool> vis;
    vector<int> ans;
    
    void dfs(int now, vector<int> adj[]) {
        vis[now]=true;
        ans.push_back(now);
        for(int neb: adj[now]) {
            if(!vis[neb]) {
                dfs(neb, adj);
            }
        }
    }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vis.resize(V);
        for(int i=0; i<V; ++i) {
            if(!vis[i]) {
                dfs(i, adj);
            }
        }
        return ans;
    }
};
