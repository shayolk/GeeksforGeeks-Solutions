class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int n=s.size(), m=p.size();
        if(n<m) {
            return "-1";
        }
        vector<int> ms(26), mp(26);
        for(char c: p) {
            ++mp[c-'a'];
        }
        int ans=n+1, cnt=0, st=0, ind=-1;
        for(int i=0; i<n; ++i) {
            ++ms[s[i]-'a'];
            if(ms[s[i]-'a']<=mp[s[i]-'a']) {
                ++cnt;
            }
            if(cnt==m) {
                while(!mp[s[st]-'a'] || mp[s[st]-'a']<ms[s[st]-'a']) {
                    if(mp[s[st]-'a']<ms[s[st]-'a']) {
                        --ms[s[st]-'a'];
                    }
                    ++st;
                }
                if(i-st+1<ans) {
                    ans=i-st+1;
                    ind=st;
                }
            }
        }
        if(ind==-1) {
            return "-1";
        }
        return s.substr(ind, ans);
    }
};
