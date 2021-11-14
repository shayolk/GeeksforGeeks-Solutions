class Solution{
	
	
	public:
	vector<long long> findMissing(long long A[], long long B[],  
                 int N, int M) 
	{
	    unordered_map<long long, bool> pres;
	    for(int i=0; i<M; ++i) {
	        pres[B[i]]=true;
	    }
	    vector<long long> ans;
	    for(int i=0; i<N; ++i) {
	        if(!pres.count(A[i])) {
	            ans.push_back(A[i]);
	        }
	    }
	    return ans;
	} 
};
