class Solution{
    const int INF=1e9+5;
    
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m) return kthElement(arr2, arr1, m, n, k);
        int lo=max(0, k-m), hi=min(n, k);
        while(lo<=hi) {
            int cut1=lo+(hi-lo)/2;
            int cut2=k-cut1;
            int l1=cut1<=0?-INF:arr1[cut1-1];
            int r1=cut1>=n?INF:arr1[cut1];
            int l2=cut2<=0?-INF:arr2[cut2-1];
            int r2=cut2>=m?INF:arr2[cut2];
            if(l1<=r2 && l2<=r1) {
                return max(l1, l2);
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
