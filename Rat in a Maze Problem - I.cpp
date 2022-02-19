// User function template for C++

class Solution{
    int dr[4]={0, 0, 1, -1};
    int dc[4]={1, -1, 0, 0};
    char dir[4]={'R', 'L', 'D', 'U'};
    int n;
    vector<vector<bool>> vis;
    vector<string> ans;
    
    bool safe(int r, int c) {
        return r>=0 && r<n && c>=0 && c<n;
    }
    
    void find(int i, int j, string& s, vector<vector<int>>& m) {
        if(i==n-1 && j==n-1) {
            ans.push_back(s);
            return;
        }
        m[i][j]=0;
        for(int d=0; d<4; ++d) {
            int r=i+dr[d], c=j+dc[d];
            if(!safe(r, c) || vis[r][c] || !m[r][c]) continue;
            vis[r][c]=true;
            s+=dir[d];
            find(r, c, s, m);
            s.pop_back();
            vis[r][c]=false;
        }
        m[i][j]=1;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(!m[0][0]) return ans;
        this->n=n;
        vis.resize(n, vector<bool> (n));
        string s;
        find(0, 0, s, m);
        return ans;
    }
};
