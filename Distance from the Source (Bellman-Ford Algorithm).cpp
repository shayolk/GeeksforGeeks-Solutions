//User function Template for C++

class Solution{
    const int INF=1e8;
    
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> dist(V, INF);
        dist[S]=0;
        for(int i=1; i<V; ++i) {
            for(auto edge: adj) {
                if(dist[edge[0]]+edge[2]<dist[edge[1]]) {
                    dist[edge[1]]=dist[edge[0]]+edge[2];
                }
            }
        }
        for(int i=1; i<V; ++i) {
            for(auto edge: adj) {
                if(dist[edge[0]]+edge[2]<dist[edge[1]]) {
                    dist[edge[1]]=-INF;
                }
            }
        }
        return dist;
    }
};
