//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        int lo=0, hi=N-1, mid, ans=N;
        while(lo<=hi) {
            mid=lo+(hi-lo)/2;
            if(Arr[mid]==k) return mid;
            if(Arr[mid]>k) {
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
