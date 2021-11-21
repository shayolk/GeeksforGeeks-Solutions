//User function template for C++

class Solution
{
    bool assign(long long per, int arr[], int n, int k) {
        long long each=arr[0];
        int need=1;
        for(int i=1; i<n; ++i) {
            if(each+arr[i]>per) {
                ++need;
                each=arr[i];
            }
            else {
                each+=arr[i];
            }
        }
        return need<=k;
    }
    
  public:
    long long minTime(int arr[], int n, int k)
    {
        long long lo=0, hi=0, mid;
        for(int i=0; i<n; ++i) {
            hi+=arr[i];
            lo=max(lo, (long long)arr[i]);
        }
        long long ans=hi;
        while(lo<=hi) {
            mid=lo+(hi-lo)/2;
            if(assign(mid, arr, n, k)) {
                ans=min(ans, mid);
                hi=mid-1;
            }
            else {
                lo=mid+1;
            }
        }
        return ans;
    }
};
