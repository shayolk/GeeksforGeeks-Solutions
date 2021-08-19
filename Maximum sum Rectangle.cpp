// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int pref[R][C+1];
        memset(pref, 0, sizeof(pref));
        for(int i=0; i<R; ++i) {
            for(int j=0; j<C; ++j) {
                pref[i][j+1]=pref[i][j]+M[i][j];
            }
        }
        int ans=-1e9-5;
        for(int i=0; i<C; ++i) {
            for(int j=i; j<C; ++j) {
                int mx=-1e9-5, so=0;
                for(int k=0; k<R; ++k) {
                    int now=pref[k][j+1]-pref[k][i];
                    so=max(now, so+now);
                    mx=max(mx, so);
                }
                ans=max(ans, mx);
            }
        }
        return ans;
    }
};
