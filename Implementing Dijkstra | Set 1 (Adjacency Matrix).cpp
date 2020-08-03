/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
vector<int> dijkstra(vector<vector<int>> g, int src, int V) {
    vector<int> dist(V, 2e9);
    dist[src]=0;
    vector<bool> done(V);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
    p.push({0,src});
    while(!p.empty()) {
        pair<int,int> pr=p.top();
        p.pop();
        int key=pr.second, val=pr.first;
        if(dist[key]<val) continue;
        done[key]=true;
        for(int neb=0; neb<V; ++neb) {
            if(g[key][neb] && !done[neb] && dist[key]+g[key][neb]<dist[neb]) {
                dist[neb]=dist[key]+g[key][neb];
                p.push({dist[neb], neb});
            }
        }
    }
    return dist;
}
