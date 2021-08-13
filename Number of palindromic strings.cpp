//User function template for C++
class Solution{
    const int M=1e9+7;
    
    long long perm(int n, int r) {
        long long ret=1;
        for(int i=n; i>n-r; --i) {
            ret=(ret*i)%M;
        }
        return ret;
    }
    
public:	
	
	int palindromicStrings(int N, int K)
	{
	    long long ans=0;
	    for(int n=1; n<=N; ++n) {
	        if(K>=n/2+n%2) {
                ans=(ans+perm(K, n/2+n%2))%M;
	        }
	    }
	    return ans;
	}
};
