class Solution {
    const int dr[4]  = {-1,   0,   0,  +1};
    const int dc[4]  = { 0,  -1,  +1,   0};
    const char ds[4] = {'U', 'L', 'R', 'D'};
    
    int n;
    vector<vector<bool>> vis;
    vector<string> ways;
    
    bool safe(int row, int col, vector<vector<int>> &mat) {
        return (row >= 0) && (row < n) && (col >= 0) && (col < n) 
               && mat[row][col] && !vis[row][col];
    }

    void traverse(int row, int col, string& way, vector<vector<int>> &mat) {
        if(row == n-1 && col == n-1) {
            ways.push_back(way);
        }
        vis[row][col] = true;
        for(int d=0; d<4; ++d) {
            int r = row + dr[d];
            int c = col + dc[d];
            char s = ds[d];
            if(!safe(r, c, mat)) {
                continue;
            }
            way += s;
            traverse(r, c, way, mat);
            way.pop_back();
        }
        vis[row][col] = false;
    }

  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        if(!mat[0][0]) {
            return ways;
        }
        n = mat.size();
        vis.resize(n, vector<bool> (n));
        string way = "";
        traverse(0, 0, way, mat);
        return ways;
    }
};
