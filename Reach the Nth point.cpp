class Solution{
    long long M=1e9+7;
    
	public:
		int nthPoint(int n){
		    if(n<=2) return n;
		    int prev2=1, prev1=2;
		    while((n--)-2) {
		        int curr=(0ll+prev1+prev2)%M;
		        prev2=prev1;
		        prev1=curr;
		    }
		    return prev1;
		}
};
