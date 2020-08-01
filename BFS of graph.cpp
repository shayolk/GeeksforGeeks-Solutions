/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) {
    vector<int> ret;
    queue<int> q;
    q.push(0);
    vector<bool> vis(N);
    vis[0]=true;
    while(!q.empty()) {
        int now=q.front();
        q.pop();
        ret.push_back(now);
        for(int neb: g[now]) {
            if(!vis[neb]) {
                q.push(neb);
                vis[neb]=true;
            }
        }
    }
    return ret;
}
