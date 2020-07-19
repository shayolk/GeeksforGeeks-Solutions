/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */

bool bfs(int start, int v, int g[][MAX], vector<int> &color)
{
    queue<int> q;
    q.push(start);
    color[start]=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int i=0; i<v; ++i)  if(i!=node && g[node][i])
        {
            if(color[i]==color[node])   return false;
            if(color[i]==-1)    color[i]=1^color[node], q.push(i);
        }
    }
    return true;
}

bool isBipartite(int g[][MAX],int v)
{
    vector<int> color(v, -1);
    for(int i=0; i<v; ++i) 
    {
        if(g[i][i]) return false;
        if(color[i]==-1) if(!bfs(i,v,g,color)) return false;
    }
    return true;
}