//User function Template for C++

class Solution {
  public:
    int makeProductOne(int arr[], int N) {
        int ans=0, zero=0, neg=0;
        for(int i=0; i<N; ++i) {
            if(arr[i]>0) {
                ans+=arr[i]-1;
                arr[i]=1;
            }
            else if(arr[i]<0) {
                ans+=-1-arr[i];
                arr[i]=-1;
                ++neg;
            }
            else {
                ++zero;
                ++ans;
            }
        }
        if(neg%2 && !zero) {
            ans+=2;
        }
        return ans;
    }
};
