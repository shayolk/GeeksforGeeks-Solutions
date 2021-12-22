class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int>> matrix, int n, int m, int x) 
    {
        int lo=0, hi=n-1, mid, row=0;
        while(lo<=hi) {
            mid=lo+(hi-lo)/2;
            if(matrix[mid][0]==x) {
                return true;
            }
            if(matrix[mid][0]<x) {
                row=max(row, mid);
                lo=mid+1;
            }
            else {
                hi=mid-1;
            }
        }
        lo=0, hi=m-1;
        while(lo<=hi) {
            mid=lo+(hi-lo)/2;
            if(matrix[row][mid]==x) {
                return true;
            }
            if(matrix[row][mid]<x) {
                lo=mid+1;
            }
            else {
                hi=mid-1;
            }
        }
        return false;
    }
};
