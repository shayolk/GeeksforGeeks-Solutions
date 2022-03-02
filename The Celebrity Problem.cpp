//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& M, int n) 
    {
        vector<int> a(n);
        iota(a.begin(), a.end(), 0);
        while(a.size()>1) {
            int A=a.back();
            a.pop_back();
            int B=a.back();
            a.pop_back();
            if(M[A][B]) a.push_back(B);
            else a.push_back(A);
        }
        assert(a.size()==1);
        for(int i=0; i<n; ++i) {
            if(i!=a[0] && (!M[i][a[0]] || M[a[0]][i])) return -1;
        }
        return a[0];
    }
};
