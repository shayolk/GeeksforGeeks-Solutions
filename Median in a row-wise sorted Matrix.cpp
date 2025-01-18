class Solution {
    int n, m, p;
    
    bool find(int num, vector<vector<int>> &mat) {
        int cnt = 0;
        for(int i=0; i<n; ++i) {
            int here = (upper_bound(mat[i].begin(), mat[i].end(), num) - mat[i].begin());
            cnt += here;
        }
        return cnt >= p;
    }

  public:
    int median(vector<vector<int>> &mat) {
        n = mat.size();
        m = mat[0].size();
        p = (n * m + 1) / 2;
        int lo = 5000, hi = 0;
        for(int i=0; i<n; ++i) {
            lo = min(lo, mat[i][0]);
            hi = max(hi, mat[i][m-1]);
        }
        int ans = hi;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(find(mid, mat)) {
                ans = min(ans, mid);
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
