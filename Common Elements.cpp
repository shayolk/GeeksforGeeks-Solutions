//Back-end complete function Template for C++

class Solution{
    public:
    vector<int> common_element(vector<int>v1,vector<int>v2)
    {
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        vector<int> ans;
        int i=0, j=0, n=v1.size(), m=v2.size();
        while(i<n && j<m) {
            if(v1[i]==v2[j]) {
                ans.push_back(v1[i]);
                ++i, ++j;
            }
            else if(v1[i]<v2[j]) {
                ++i;
            }
            else {
                ++j;
            }
        }
        return ans;
    }
};
