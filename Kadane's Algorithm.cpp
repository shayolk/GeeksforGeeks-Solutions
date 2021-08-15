class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        int ans=-1e9-5, so=0;
        for(int i=0; i<n; ++i) {
            so=max(arr[i], so+arr[i]);
            ans=max(ans, so);
        }
        return ans;
    }
};
