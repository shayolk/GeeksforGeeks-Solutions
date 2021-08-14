// Function to return minimum number of jumps to end of array

class Solution{
    const int INF=1e9+5;
    
  public:
    int minJumps(int arr[], int n){
        int mx=0, cur=0, jumps=0;
        for(int i=0; i<n-1; ++i) {
            mx=max(mx, i+arr[i]);
            if(i==cur) {
                ++jumps;
                cur=mx;
            }
            if(cur>=n-1) {
                break;
            }
        }
        if(cur<n-1) {
            return -1;
        }
        return jumps;
    }
};
