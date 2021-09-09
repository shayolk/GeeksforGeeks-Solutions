class Solution {
    vector<vector<int>> adj;
    vector<bool> vis, rec;
    
    bool dfs(int now) {
        vis[now]=true;
        rec[now]=true;
        for(int neb: adj[now]) {
            if(rec[neb] || (!vis[neb] && dfs(neb))) return true;
        }
        rec[now]=false;
        return false;
    }
    
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    adj.resize(N);
	    vis.resize(N);
	    rec.resize(N);
	    for(auto p: prerequisites) {
	        adj[p.second].push_back(p.first);
	    }
	    for(int i=0; i<N; ++i) {
	        if(!vis[i]) {
	            if(dfs(i)) return false;
	        }
	    }
	    return true;
	}
};
