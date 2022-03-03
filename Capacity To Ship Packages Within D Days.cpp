//User function Template for C++

class Solution {
    bool check(int weights[], int n, int days, int per) {
        int need=1, each=0;
        for(int i=0; i<n; ++i) {
            each+=weights[i];
            if(each>per) {
                ++need;
                each=weights[i];
            }
        }
        return need<=days;
    }
    
  public:
    int leastWeightCapacity(int arr[], int N, int D) {
        int lo=0, hi=0;
        for(int i=0; i<N; ++i) {
            lo=max(lo, arr[i]);
            hi+=arr[i];
        }
        int ans=hi;
        while(lo<=hi) {
            int mid=lo+(hi-lo)/2;
            if(check(arr, N, D, mid)) {
                ans=mid;
                hi=mid-1;
            }
            else {
                lo=mid+1;
            }
        }
        return ans;
    }
};
