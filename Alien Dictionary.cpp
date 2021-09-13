/*
dict : array of strings denoting the words in alien langauge
N : Size of the dictionary
K : Number of characters
*/

// User function Template for C++

class Solution{
    vector<set<int>> adj;
    vector<bool> vis;
    string topo;
    
    void dfs(int now) {
        vis[now]=true;
        for(int neb: adj[now]) {
            if(!vis[neb]) dfs(neb);
        }
        topo+=('a'+now);
    }
    
    public:
    string findOrder(string dict[], int N, int K) {
        adj.resize(K);
        vis.resize(K);
        for(int i=1; i<N; ++i) {
            for(int j=0; j<min(dict[i-1].size(), dict[i].size()); ++j) {
                if(dict[i-1][j]!=dict[i][j]) {
                    adj[dict[i-1][j]-'a'].insert(dict[i][j]-'a');
                    break;
                }
            }
        }
        for(int i=0; i<K; ++i) {
            if(!vis[i]) dfs(i);
        }
        reverse(topo.begin(), topo.end());
        return topo;
    }
};
