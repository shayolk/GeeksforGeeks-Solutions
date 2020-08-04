/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/
void dfs(int now, int& sc, int& id, stack<int>& s, vector<int>& ids, vector<int>& low, vector<bool>& cur, vector<int> adj[]) {
    s.push(now);
    cur[now]=true;
    ids[now]=low[now]=id++;
    for(int neb: adj[now]) {
        if(ids[neb]==-1) dfs(neb,sc,id,s,ids,low,cur,adj);
        if(cur[neb]) low[now]=min(low[now], low[neb]);
    }
    if(ids[now]==low[now]) {
        int node=-1;
        while(node!=now) {
            node=s.top();
            s.pop();
            cur[node]=false;
            low[node]=ids[now];
        }
        ++sc;
    }
}

int kosaraju(int v, vector<int> adj[]) {
    /* Tarjans Algorithm */
    vector<int> ids(v, -1), low(v, -1);
    vector<bool> cur(v);
    int id=0, sc=0;
    stack<int> s;
    for(int i=0; i<v; ++i) {
        if(ids[i]==-1) {
            dfs(i,sc,id,s,ids,low,cur,adj);
        }
    }
    return sc;
}
