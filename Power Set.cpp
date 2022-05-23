class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    int n=s.size();
		    vector<string> ans;
		    for(int bit=0; bit<(1<<n); ++bit) {
		        string now="";
		        for(int i=0; i<n; ++i) {
		            if(bit & (1<<i)) {
		                now+=s[i];
		            }
		        }
		        if(!now.empty()) ans.push_back(now);
		    }
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};
