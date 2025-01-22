class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        int l = 0, r = n - 1;
        while(l < r) {
            if(mat[l][r]) {
                ++l;
            }
            else {
                --r;
            }
        }
        for(int i=0; i<n; ++i) {
            if(mat[l][i]) {
                return -1;
            }
            if(i != l && mat[i][l] == 0) {
                return -1;
            }
        }
        return l;
    }
};
