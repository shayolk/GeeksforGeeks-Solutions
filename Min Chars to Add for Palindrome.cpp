class Solution {
  public:
    int minChar(string& s) {
        int m = s.size();
        s = s + '-' + s;
        reverse(s.begin() + m + 1, s.end());
        int n = s.size();
        vector<int> pi(n);
        for(int i = 1; i < n; ++i) {
            int j = pi[i - 1];
            while(j > 0 && s[i] != s[j]) {
                j = pi[j - 1];
            }
            if(s[i] == s[j]) {
                ++j;
            }
            pi[i] = j;
        }
        return m - pi[n - 1];
    }
};
