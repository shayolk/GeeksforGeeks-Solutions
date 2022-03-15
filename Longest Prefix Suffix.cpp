//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    int n=s.size();
        vector<int> lps(n);
        for(int i=1; i<n; ++i) {
            int j=lps[i-1];
            while(j && s[i]!=s[j]) {
                j=lps[j-1];
            }
            if(s[i]==s[j]) lps[i]=j+1;
        }
        return lps[n-1];
	}
};
