/* The function returns a  vector of strings 
present in the dictionary which matches
the string pattern.
You are required to complete this method */
vector<string> findMatchedWords(vector<string> dict, string pattern) {
    map<char,char> m;
    int i=0;
    string p, s;
    for(char c: pattern) {
        if(m.count(c)) {
            p+=m[c];
        }
        else {
            m[c]='a'+i++;
            p+=m[c];
        }
    }
    vector<string> ans;
    for(string st: dict) {
        i=0;
        m.clear();
        s.clear();
        for(char c: st) {
            if(m.count(c)) {
                s+=m[c];
            }
            else {
                m[c]='a'+i++;
                s+=m[c];
            }
        }
        if(s==p) ans.push_back(st);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
