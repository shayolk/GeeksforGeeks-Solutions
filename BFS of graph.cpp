class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        queue<int> q;
        q.push(0);
        vector<bool> vis(V);
        vis[0]=true;
        while(!q.empty()) {
            int now=q.front();
            q.pop();
            ans.push_back(now);
            for(int neb: adj[now]) {
                if(!vis[neb]) {
                    q.push(neb);
                    vis[neb]=true;
                }
            }
        }
        return ans;
    }
};
