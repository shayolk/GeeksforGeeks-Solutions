class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0, sum = 0;
        map<int,int> cnt;
        cnt[0] = -1;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            if (cnt.count(sum - k)) {
                ans = max(ans, i - cnt[sum - k]);
            }
            if (!cnt.count(sum)) {
                cnt[sum] = i;
            }
        }
        return ans;
    }
};
