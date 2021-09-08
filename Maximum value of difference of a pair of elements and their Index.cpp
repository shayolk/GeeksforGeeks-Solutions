//User function Template for C++

class Solution {
    const int INF=1e9+5;
  public:
    int maxValue(int arr[], int N) {
        int min1=INF, min2=INF, max1=-INF, max2=-INF;
        for(int i=0; i<N; ++i) {
            min1=min(min1, arr[i]+i);
            min2=min(min2, arr[i]-i);
            max1=max(max1, arr[i]+i);
            max2=max(max2, arr[i]-i);
        }
        return max(max1-min1, max2-min2);
    }
};
