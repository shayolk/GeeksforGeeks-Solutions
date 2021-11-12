//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    if(arr[0]>arr[1]) return arr[0];
	    int lo=0, hi=n-1, mid;
	    while(lo<=hi) {
	        mid=lo+(hi-lo)/2;
	        if(mid==0) {
	            lo=mid+1;
	            continue;
	        }
	        if(mid==n-1) {
	            hi=mid-1;
	            continue;
	        }
	        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return arr[mid];
	        if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]) lo=mid+1;
	        else hi=mid-1;
	    }
	    return arr[n-1];
	}
};
