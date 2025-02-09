class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(mat[i][k] == -1 || mat[k][j] == -1) {
                        continue;
                    }
                    int poss_dist = mat[i][k] + mat[k][j];
                    if(mat[i][j] == -1 || poss_dist < mat[i][j]) {
                        mat[i][j] = poss_dist;
                    }
                }
            }
        }
    }
};
