/*
dict : array of strings denoting the words in alien langauge
N : Size of the dictionary
K : Number of characters
*/
void dfs(int now, vector<set<int>>& adj, vector<bool>& vis, string& topo) {
    vis[now]=true;
    for(auto neb=adj[now].begin(); neb!=adj[now].end(); ++neb) {
        if(!vis[*neb]) {
            dfs(*neb,adj,vis,topo);
        }
    }
    topo+='a'+now;
}

string findOrder(string dict[], int N, int K) {
    vector<set<int>> adj(K);
    for(int i=1; i<N; ++i) {
        for(int j=0; j<min((int)dict[i-1].size(), (int)dict[i].size()); ++j) {
            if(dict[i-1][j]!=dict[i][j]) {
                adj[dict[i-1][j]-'a'].insert(dict[i][j]-'a');
                break;
            }
        }
    }
    vector<bool> vis(K);
    string topo;
    for(int i=0; i<K; ++i) {
        if(!vis[i]) {
            dfs(i,adj,vis,topo);
        }
    }
    reverse(topo.begin(), topo.end());
    return topo;
}
