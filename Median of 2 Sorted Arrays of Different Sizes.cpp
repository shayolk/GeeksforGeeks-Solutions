//User function Template for C++

class Solution{
    const int INF=1e9+5;
    
    public:
    double MedianOfArrays(vector<int>& arr1, vector<int>& arr2)
    {
        int n=arr1.size(), m=arr2.size(), k=(n+m+1)/2;
        if(n>m) return MedianOfArrays(arr2, arr1);
        int lo=max(0, k-m), hi=min(n, k);
        while(lo<=hi) {
            int cut1=lo+(hi-lo)/2;
            int cut2=k-cut1;
            int l1=cut1<=0?-INF:arr1[cut1-1];
            int r1=cut1>=n?INF:arr1[cut1];
            int l2=cut2<=0?-INF:arr2[cut2-1];
            int r2=cut2>=m?INF:arr2[cut2];
            if(l1<=r2 && l2<=r1) {
                if((n+m)%2) return max(l1, l2);
                return (max(l1, l2)+min(r1, r2))/2.0;
            }
            if(l1>r2) {
                hi=cut1-1;
            }
            else {
                lo=cut1+1;
            }
        }
        return -1;
    }
};
