// User function Template for C++

class Solution{
public:
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        int pref[n+1];
        pref[0]=0;
        for(int i=0; i<n; ++i) {
            pref[i+1]=arr[i]+pref[i];
        }
        vector<int> ans;
        for(int i=0; i<2*q; i+=2) {
            ans.push_back(pref[queries[i+1]]-pref[queries[i]-1]);
        }
        return ans;
    }
};
