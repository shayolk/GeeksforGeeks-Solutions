class Solution {
    using edge = pair<int,int>;
    using low_pq_edges = priority_queue<edge,vector<edge>,greater<edge>>;

  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> vis(V);
        int sum = 0;
        low_pq_edges pq;
        
        auto visitAndAddEdges = [&](int now) {
            vis[now] = true;
            for(vector<int> vi: adj[now]) {
                int neb = vi[0];
                int cost = vi[1];
                pq.push({cost, neb});
            }
        };
        
        visitAndAddEdges(0);
        while(!pq.empty()) {
            edge e = pq.top();
            pq.pop();
            int cost = e.first;
            int neb = e.second;
            if(vis[neb]) {
                continue;
            }
            sum += cost;
            visitAndAddEdges(neb);
        }
        return sum;
    }
};
