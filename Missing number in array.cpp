// User function template for C++

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        int x=n;
        for(int i=1; i<n; ++i) {
            x^=i;
            x^=array[i-1];
        }
        return x;
    }
};
