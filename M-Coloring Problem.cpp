//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool safe(int now, int c, int& n, vector<int>& color, bool adj[101][101]) {
    for(int neb=0; neb<n; ++neb) {
        if(neb!=now && adj[now][neb] && color[neb]==c) {
            return false;
        }
    }
    return true;
}

bool mcol(int now, int& n, int m, vector<int>& color, bool adj[101][101]) {
    if(now==n) {
        return true;
    }
    for(int c=0; c<m; ++c) {
        if(safe(now, c, n, color, adj)) {
            color[now]=c;
            if(mcol(now+1, n, m, color, adj)) {
                return true;
            }
            color[now]=-1;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> color(V, -1);
    return mcol(0, V, m, color, graph);
}
