//User function template for C++

class Solution {
    vector<vector<int>> ans;
    
    void find(int beg, int sum, int b, vector<int> now, vector<int> &a) {
        if(sum>b) return;
        if(sum==b) {
            ans.push_back(now);
            return;
        }
        for(int i=beg; i<a.size(); ++i) {
            now.push_back(a[i]);
            if(sum+a[i]<=b) find(i, sum+a[i], b, now, a);
            now.pop_back();
        }
    }
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        find(0, 0, B, vector<int>{}, A);
        return ans;
    }
};
