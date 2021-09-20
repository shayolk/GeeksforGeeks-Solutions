//User function template for C++

class Solution{
  public:
    int rightmostNonZeroDigit(int N, int A[]){
        int cnt=0;
        for(int i=0; i<N; ++i) {
            while(A[i] && A[i]%5==0) {
                A[i]/=5;
                ++cnt;
            }
        }
        int ans=1;
        for(int i=0; i<N; ++i) {
            while(cnt && A[i] && A[i]%2==0) {
                A[i]/=2;
                --cnt;
            }
            ans=(ans*(A[i]%10))%10;
        }
        if(cnt) ans=(ans*5)%10;
        return ans?ans%10:-1;
    }
};
