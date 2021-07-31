class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // vector<pair<int,int>> a;
        // for(int i=0; i<n; ++i) {
        //     a.push_back({arr[i], dep[i]});
        // }
        // sort(a.begin(), a.end());
        sort(arr, arr+n);
        sort(dep, dep+n);
        int ans=0, i=0, j=0;
        while(i<n && j<n) {
            if(arr[i]<=dep[j]) {
                ++ans;
            }
            else {
                ++j;
            }
            ++i;
        }
        return ans;
    }
};
