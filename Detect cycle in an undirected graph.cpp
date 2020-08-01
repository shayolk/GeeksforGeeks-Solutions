/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/
bool isCyclic(vector<int> g[], int V) {
    vector<bool> vis(V);
    vector<int> par(V, -1);
    for(int i=0; i<V; ++i) if(!vis[i]) {
        vis[i]=true;
        stack<int> s;
        s.push(i);
        par[i]=i;
        while(!s.empty()) {
            int now=s.top();
            s.pop();
            for(int neb: g[now]) {
                if(vis[neb]) {
                    if(par[now]!=neb) return true;
                    continue;
                }
                vis[neb]=true;
                s.push(neb);
                par[neb]=now;
            }
        }
    }
    return false;
}
