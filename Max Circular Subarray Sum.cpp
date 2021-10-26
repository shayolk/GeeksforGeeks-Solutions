class Solution{
    const int INF=1e9+5;

    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int n){
        int ans=-INF, so=0;
        for(int i=0; i<n; ++i) {
            so=max(arr[i], so+arr[i]);
            ans=max(ans, so);
        }
        vector<int> suff(n);
        so=suff[n-1]=arr[n-1];
        for(int i=n-2; i>=0; --i) {
            so+=arr[i];
            suff[i]=max(suff[i+1], so);
        }
        so=0;
        for(int i=0; i<n-2; ++i) {
            so+=arr[i];
            ans=max(ans, so+suff[i+2]);
        }
        return ans;
    }
};
