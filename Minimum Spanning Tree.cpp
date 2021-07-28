class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int ans=0;
        vector<int> dist(V, 2e9+5);
        vector<bool> vis(V);
        dist[0]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
        p.push({0,0});
        while(!p.empty()) {
            pair<int,int> t=p.top();
            p.pop();
            int wt=t.first, now=t.second;
            if(vis[now]) {
                continue;
            }
            vis[now]=true;
            ans+=wt;
            for(auto neb: adj[now]) {
                if(!vis[neb[0]] && neb[1]<dist[neb[0]]) {
                    dist[neb[0]]=neb[1];
                    p.push({neb[1], neb[0]});
                }
            }
        }
        return ans;
    }
};
