class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        long n=v.size();
        long l=n, r=-1;
        long lo=0, hi=n-1, mid;
        while(lo<=hi) {
            mid=lo+(hi-lo)/2;
            if(v[mid]>=x) {
                if(v[mid]==x) l=min(l, mid);
                hi=mid-1;
            }
            else {
                lo=mid+1;
            }
        }
        lo=0, hi=n-1;
        while(lo<=hi) {
            mid=lo+(hi-lo)/2;
            if(v[mid]>x) {
                hi=mid-1;
            }
            else {
                if(v[mid]==x) r=max(r, mid);
                lo=mid+1;
            }
        }
        if(l==n || r==-1) return {-1, -1};
        return {l, r};
    }
};
