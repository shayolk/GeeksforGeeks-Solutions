class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        int xr = 0, ans = 0;
        map<int,int> ind;
        ind[0] = 1;
        for (int i = 0; i < n; ++i) {
            xr ^= arr[i];
            if (ind.count(xr ^ k)) {
                ans += ind[xr ^ k];
            }
            ++ind[xr];
        }
        return ans;
    }
};
