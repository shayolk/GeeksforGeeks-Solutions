class Solution {
    int v;
    int m;
    vector<set<int>> nebs;
    vector<int> col;
    vector<bool> vis;
    
    bool safe(int now, int c) {
        for(int neb: nebs[now]) {
            if(col[neb] == c) {
                return false;
            }
        }
        return true;
    }
    
    bool find(int now) {
        if(now == v) {
            return true;
        }
        for(int c=0; c<m; ++c) {
            if(safe(now, c)) {
                col[now] = c;
                if(find(now + 1)) {
                    return true;
                }
                col[now] = -1;
            }
        }
        return false;
    }

  public:
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        this->v = v;
        this->m = m;
        nebs.resize(v);
        col.resize(v, -1);
        vis.resize(v);
        for(auto e: edges) {
            nebs[e.first].insert(e.second);
            nebs[e.second].insert(e.first);
        }
        return find(0);
    }
};
