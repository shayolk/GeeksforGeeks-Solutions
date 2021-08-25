class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int n=txt.size(), m=pat.size();
            vector<int> ans;
            for(int i=0; i<n; ++i) {
                if(txt[i]!=pat[0]) continue;
                if(i+m>n) break;
                if(txt.substr(i, m)==pat) {
                    ans.push_back(i+1);
                }
            }
            if(ans.empty()) ans.push_back(-1);
            return ans;
        }
     
};
