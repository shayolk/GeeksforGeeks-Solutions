//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        map<string,vector<string>> mp;
        for(string s: string_list) {
            string d=s;
            sort(d.begin(), d.end());
            mp[d].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto m: mp) {
            ans.push_back(m.second);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
