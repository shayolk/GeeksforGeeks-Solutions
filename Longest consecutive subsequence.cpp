class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        int mx=*max_element(arr, arr+N);
        vector<int> cnt(mx+1);
        for(int i=0; i<N; ++i) {
            ++cnt[arr[i]];
        }
        int so=cnt[0]>0;
        int ans=so;
        for(int i=1; i<=mx; ++i) {
            if(cnt[i]) {
                if(cnt[i-1]) ++so;
                else so=1;
            }
            ans=max(ans, so);
        }
        return ans;
    }
};
