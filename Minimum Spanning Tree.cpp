// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
int spanningTree(int v, int e, vector<vector<int>> &graph) {
    // code here
    vector<bool> done(v);
    done[0]=true;
    vector<int> par(v);
    par[0]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
    for(int j=1; j<v; ++j) {
        par[j]=j;
        p.push({graph[0][j], j});
        if(graph[0][j]!=INT_MAX) {
            par[j]=0;
        }
    }
    int wt=0, last=0;
    while(!p.empty()) {
        pair<int,int> pr=p.top();
        p.pop();
        last=pr.second;
        if(done[last]) continue;
        // wt+=graph[par[last]][last];
        wt+=pr.first;
        done[last]=true;
        for(int j=0; j<v; ++j) {
            if(!done[j] && graph[last][j]!=INT_MAX && graph[last][j]<graph[par[j]][j]) {
                p.push({graph[last][j], j});
                par[j]=last;
            }
        }
    }
    return wt;
}
