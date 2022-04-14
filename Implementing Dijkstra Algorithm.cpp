class Solution
{
    const int INF=1e9+5;
    
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, INF);
        dist[S]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0, S});
        vector<bool> done(V);
        while(!pq.empty()) {
            pair<int,int> p=pq.top();
            pq.pop();
            int val=p.first, now=p.second;
            if(dist[now]<val) continue;
            done[now]=true;
            for(auto neb: adj[now]) {
                if(done[neb[0]] || dist[neb[0]]<=val+neb[1]) continue;
                dist[neb[0]]=val+neb[1];
                pq.push({dist[neb[0]], neb[0]});
            }
        }
        return dist;
    }
};
