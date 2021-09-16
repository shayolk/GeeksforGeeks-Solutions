class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > a, int n, int m) 
    {
        vector<int> ans;
        int i=0, j=-1, dir=0, horl=0, horr=m-1, verl=0, verr=n-1;
        while(horl<=horr && verl<=verr) {
            if(dir==0) {
                ++j;
                while(j<=horr) ans.push_back(a[i][j++]);
                --j;
                ++verl;
            }
            else if(dir==1) {
                ++i;
                while(i<=verr) ans.push_back(a[i++][j]);
                --i;
                --horr;
            }
            else if(dir==2) {
                --j;
                while(j>=horl) ans.push_back(a[i][j--]);
                ++j;
                --verr;
            }
            else {
                --i;
                while(i>=verl) ans.push_back(a[i--][j]);
                ++i;
                ++horl;
            }
            dir=(dir+1)%4;
        }
        return ans;
    }
};
