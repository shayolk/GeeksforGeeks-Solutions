//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        int n=arr.size();
        vector<int> cnt(26);
        for(char c: arr) {
            ++cnt[c-'a'];
        }
        for(int i=1; i<26; ++i) {
            cnt[i]+=cnt[i-1];
        }
        string ans(n, '.');
        for(char c: arr) {
            ans[cnt[c-'a']-1]=c;
            --cnt[c-'a'];
        }
        return ans;
    }
};
