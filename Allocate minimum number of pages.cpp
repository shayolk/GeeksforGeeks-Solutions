//User function template in C++

class Solution 
{
    bool check(int mid, int a[], int n, int m) {
        int req=1, sum=a[0];
        for(int i=1; i<n; ++i) {
            sum+=a[i];
            if(sum>mid) {
                ++req;
                sum=a[i];
            }
        }
        return req<=m;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N) return -1;
        int lo=0, hi=0, ans=-1;
        for(int i=0; i<N; ++i) {
            lo=max(lo, A[i]);
            hi+=A[i];
        }
        while(lo<=hi) {
            int mid=lo+(hi-lo)/2;
            if(check(mid, A, N, M)) {
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
