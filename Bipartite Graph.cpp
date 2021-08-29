class Solution {
    vector<int> color;
    
    bool check(int now, int col, int v, vector<int>adj[]) {
        color[now]=col;
        int here=true;
        for(int neb: adj[now]) {
            if(color[neb]!=-1) {
                if(color[neb]==col) return false;
                continue;
            }
            if(!check(neb, 1-col, v, adj)) return false;
        }
        return true;
    }
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    color.resize(V, -1);
	    for(int i=0; i<V; ++i) {
	        if(color[i]==-1) {
	            if(!check(i, 0, V, adj)) return false;
	        }
	    }
	    return true;
	}

};
