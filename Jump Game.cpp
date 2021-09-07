//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int N) {
        int ind=N-1;
        for(int i=N-2; i>=0; --i) {
            if(i+A[i]>=ind) {
                ind=i;
            }
        }
        return ind==0;
    }
};
