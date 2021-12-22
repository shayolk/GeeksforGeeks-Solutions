class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        long long ans=0;
        for(long long s=1; s<=N; ++s) {
            ans+=(N-s+1)*(N-s+1);
        }
        return ans;
    }
};
