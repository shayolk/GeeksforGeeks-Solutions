//User function Template for C++

class Solution{
public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr+n);
        int diff=arr[n-1]-arr[0];
        for(int i=1; i<n; ++i) {
            int mn=min(arr[i]-k, arr[0]+k);
            int mx=max(arr[i-1]+k, arr[n-1]-k);
            diff=min(diff, mx-mn);
        }
        return diff;
    }
};
