//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    vector<int> pos, neg;
	    for(int i=0; i<n; ++i) {
	        if(arr[i]>=0) pos.push_back(arr[i]);
	        else neg.push_back(arr[i]);
	    }
	    reverse(pos.begin(), pos.end());
	    reverse(neg.begin(), neg.end());
	    int i=0;
	    while(i<n) {
	        if(!pos.empty()) {
	            arr[i++]=pos.back();
	            pos.pop_back();
	        }
	        if(!neg.empty()) {
	            arr[i++]=neg.back();
	            neg.pop_back();
	        }
	    }
	}
};
