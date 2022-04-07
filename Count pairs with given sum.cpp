//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        map<int,int> cnt;
        int ans=0;
        for(int i=0; i<n; ++i) {
            if(cnt.count(k-arr[i])) ans+=cnt[k-arr[i]];
            ++cnt[arr[i]];
        }
        return ans;
    }
};
