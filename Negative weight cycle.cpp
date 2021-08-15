class Solution {
    const int INF=2e9+5;
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist(n, INF);
	    dist[0]=0;
	    for(int i=1; i<n; ++i) {
	        for(auto e: edges) {
	            if(dist[e[0]]!=INF) {
	                dist[e[1]]=min(dist[e[1]], dist[e[0]]+e[2]);
	            }
	        }
	    }
	    for(int i=1; i<n; ++i) {
	        for(auto e: edges) {
    	       // if(dist[e[0]]==INF) {
    	       //     return 1;
    	       // }
    	        if(dist[e[0]]+e[2]<dist[e[1]]) {
    	            dist[e[1]]=INF;
    	            return 1;
    	        }
	        }
	    }
	    return 0;
	}
};
