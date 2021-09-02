class Solution {
  public:
    int getCount(int n) {
        int ans=0;
        for(int i=1; i*i<=2*n; ++i) {
            int here=i*(i-1)/2;
            if(n-here<0) break;
            if((n-here)%i==0) ++ans;
        }
        return ans-1;
    }
};
