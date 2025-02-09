class Solution {
    const int INF = 1e8;

  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, INF);
        dist[src] = 0;
        for(int i = 1; i < V; ++i) {
            for(vector<int> edge: edges) {
                int now = edge[0];
                int neb = edge[1];
                int cost = edge[2];
                if(dist[now] == INF) {
                    continue;
                }
                dist[neb] = min(dist[neb], dist[now] + cost);
            }
        }
        for(int i = 1; i < V; ++i) {
            for(vector<int> edge: edges) {
                int now = edge[0];
                int neb = edge[1];
                int cost = edge[2];
                if(dist[now] == INF) {
                    continue;
                }
                if(dist[now] + cost < dist[neb]) {
                    return {-1};
                }
            }
        }
        return dist;
    }
};
