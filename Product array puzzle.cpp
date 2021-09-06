//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<long long> right(n+1, 1), ans(n);
        for(int i=n-1; i>=0; --i) {
            right[i]=nums[i]*right[i+1];
        }
        long long left=1;
        for(int i=0; i<n; ++i) {
            ans[i]=left*right[i+1];
            left*=nums[i];
        }
        return ans;
    }
};
