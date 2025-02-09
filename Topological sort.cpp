class Solution {
    int n;
    vector<bool> vis;
    vector<int> topo_order;
    
    void dfs(int now, vector<vector<int>>& adj) {
        vis[now] = true;
        for(int neb: adj[now]) {
            if(!vis[neb]) {
                dfs(neb, adj);
            }
        }
        topo_order.push_back(now);
    }
    
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        n = adj.size();
        vis.resize(n);
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                dfs(i, adj);
            }
        }
        reverse(topo_order.begin(), topo_order.end());
        return topo_order;
    }
};
