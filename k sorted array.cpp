//User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k)
    {
        vector<pair<int, int>> a;
        for(int i=0; i<n; ++i) {
            a.push_back({arr[i], i});
        }
        sort(a.begin(), a.end());
        for(int i=0; i<n; ++i) {
            if(abs(a[i].second-i)>k) return "No";
        }
        return "Yes";
    }
};
