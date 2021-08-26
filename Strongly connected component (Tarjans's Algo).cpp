//User function template for C++

class Solution
{
    vector<vector<int>> ans;
    vector<int> ids, low;
    vector<bool> onst;
    stack<int> st;
    int id, scc;
    
    void dfs(int now, vector<int> adj[]) {
        ids[now]=low[now]=++id;
        st.push(now);
        onst[now]=true;
        for(int neb: adj[now]) {
            if(ids[neb]==-1) {
                dfs(neb, adj);
            }
            if(onst[neb]) {
                low[now]=min(low[now], low[neb]);
            }
        }
        if(ids[now]==low[now]) {
            vector<int> comp;
            while(!st.empty()) {
                int node=st.top();
                st.pop();
                comp.push_back(node);
                low[node]=low[now];
                onst[node]=false;
                if(node==now) break;
            }
            sort(comp.begin(), comp.end());
            ans.push_back(comp);
            ++scc;
        }
    }
    
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        ids.resize(V, -1);
        low.resize(V, -1);
        onst.resize(V, false);
        id=scc=0;
        for(int i=0; i<V; ++i) {
            if(ids[i]==-1) {
                dfs(i, adj);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
