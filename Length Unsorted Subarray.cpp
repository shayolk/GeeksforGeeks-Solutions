//User function template for C++
class Solution{
public:	
	vector<int> printUnsorted(int arr[], int n) {
	    vector<int> ans{0, 0};
	    for(int i=0; i<n-1; ++i) {
	        if(arr[i]>arr[i+1]) {
	            ans[0]=i;
	            break;
	        }
	    }
	    for(int i=n-1; i>0; --i) {
	        if(arr[i]<arr[i-1]) {
	            ans[1]=i;
	            break;
	        }
	    }
	    if(ans[0]==0 && ans[1]==0) {
	        return ans;
	    }
	    int mn=arr[ans[0]], mx=arr[ans[0]];
	    for(int i=ans[0]+1; i<=ans[1]; ++i) {
	        mn=min(mn, arr[i]);
	        mx=max(mx, arr[i]);
	    }
	    for(int i=0; i<ans[0]; ++i) {
	        if(arr[i]>mn) {
	            ans[0]=i;
	            break;
	        }
	    }
	    for(int i=n-1; i>ans[1]; --i) {
	        if(arr[i]<mx) {
	            ans[1]=i;
	            break;
	        }
	    }
	    return ans;
	}
};
