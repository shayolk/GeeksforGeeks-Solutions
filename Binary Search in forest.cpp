class Solution{
    int sum(int tree[], int n, int h) {
        int res=0;
        for(int i=0; i<n; ++i) {
            res+=tree[i]>h?tree[i]-h:0;
        }
        return res;
    }
    
    public:
    int find_height(int tree[], int n, int k)
    {
        sort(tree, tree+n);
        int lo=0, hi=tree[n-1], mid;
        while(lo<=hi) {
            mid=lo+(hi-lo)/2;
            int s=sum(tree, n, mid);
            if(s==k) return mid;
            if(s<k) hi=mid-1;
            else lo=mid+1;
        }
        return -1;
    }
};
