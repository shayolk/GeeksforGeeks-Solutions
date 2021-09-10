//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        vector<bool> pos(26);
        for(int i=0; i<patt.size(); ++i) {
            pos[patt[i]-'a']=true;
        }
        for(int i=0; i<str.size(); ++i) {
            if(pos[str[i]-'a']) {
                return i;
            }
        }
        return -1;
    }
};
