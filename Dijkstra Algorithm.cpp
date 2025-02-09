class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n = adj.size();
        vector<bool> vis(n);
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0, src});
        while(!pq.empty()) {
            pair<int,int> p = pq.top();
            pq.pop();
            int dis = p.first;
            int now = p.second;
            vis[now] = true;
            if(dist[now] < dis) {
                continue;
            }
            for(pair<int,int> pii: adj[now]) {
                int neb = pii.first;
                int wt = pii.second;
                if(vis[neb]) {
                    continue;
                }
                int new_dis = dist[now] + wt;
                if(new_dis < dist[neb]) {
                    dist[neb] = new_dis;
                    pq.push({new_dis, neb});
                }
            }
        }
        return dist;
    }
};
