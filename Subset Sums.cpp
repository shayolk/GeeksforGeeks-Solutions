class Solution
{
    vector<int> ans;
    
    void find(int i, int n, int sum, vector<int>& a) {
        if(i==n) {
            ans.push_back(sum);
            return;
        }
        find(i+1, n, sum, a);
        find(i+1, n, sum+a[i], a);
    }
    
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        find(0, N, 0, arr);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
