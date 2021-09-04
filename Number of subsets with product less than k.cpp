//User function Template for C++

class Solution {
    vector<long long> divide(int a[], int st, int ed, int k) {
        if(st>ed) return {};
        if(st==ed) return {a[st]};
        vector<long long> prods;
        for(int mask=1; mask<(1<<(ed-st+1)); ++mask) {
            long long prod=1;
            for(int i=st; i<=ed; ++i) {
                if(mask & (1<<(i-st))) {
                    prod*=a[i];
                }
            }
            if(prod<=k) prods.push_back(prod);
        }
        sort(prods.begin(), prods.end());
        return prods;
    }
  public:
    int numOfSubsets(int arr[], int N, int K) {
        vector<long long> left=divide(arr, 0, N/2-1, K), right=divide(arr, N/2, N-1, K);
        int l=upper_bound(left.begin(), left.end(), K)-left.begin();
        int r=upper_bound(right.begin(), right.end(), K)-right.begin();
        int ans=l+r;
        for(long long l: left) {
            if(l>K) break;
            ans+=upper_bound(right.begin(), right.end(), K/l)-right.begin();
        }
        return ans;
    }
};
