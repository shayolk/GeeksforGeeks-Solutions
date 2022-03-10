class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> ans;
        for(int i=0; i<n; ++i) {
            arr[arr[i]%n]+=n;
        }
        for(int i=0; i<n; ++i) {
            if(arr[i]/n>1) ans.push_back(i);
        }
        if(ans.empty()) ans.push_back(-1);
        return ans;
    }
};
