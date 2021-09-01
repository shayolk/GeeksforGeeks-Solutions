//User function Template for C++


class Solution{
	public:
    long long findNth(long long N)
    {
        long long ans=0, mul=1;
        while(N) {
            ans=N%9*mul+ans;
            N/=9;
            mul*=10;
        }
        return ans;
    }
};
