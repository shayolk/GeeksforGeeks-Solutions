class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    {
        int left[N], right[N];
        left[0]=0;
        for(int i=1; i<N; ++i) {
            left[i]=i;
            if(A[left[i-1]]<=A[i]) left[i]=left[i-1];
        }
        right[N-1]=N-1;
        for(int i=N-2; i>=0; --i) {
            right[i]=i;
            if(A[right[i+1]]>=A[i]) right[i]=right[i+1];
        }
        int ans=0, i=0, j=0;
        while(i<N && j<N) {
            if(A[left[i]]<=A[right[j]]) {
                ans=max(ans, right[j]-left[i]);
                ++j;
            }
            else {
                ++i;
            }
        }
        return ans;
    }
};
