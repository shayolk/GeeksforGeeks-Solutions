class Solution{
public:
    string chooseandswap(string a){
        int n=a.size();
        vector<int> pos(26);
        for(int i=0; i<n; ++i) {
            if(!pos[a[i]-'a']) {
                pos[a[i]-'a']=i+1;
            }
        }
        for(int i=0; i<n; ++i) {
            for(int j=0; j<a[i]-'a'; ++j) {
                if(pos[j]-1>i) {
                    char c=a[i], d='a'+j;
                    for(char& i: a) {
                        if(i==c) {
                            i=d;
                        }
                        else if(i==d) {
                            i=c;
                        }
                    }
                    return a;
                }
            }
        }
        return a;
    }
    
};
