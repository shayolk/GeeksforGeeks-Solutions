//User function template for C++

class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        int lo=0, hi=n-1;
        while(lo<=hi) {
            if(arr[lo]==0) {
                ++lo;
            }
            else if(arr[hi]==1) {
                --hi;
            }
            else {
                swap(arr[lo++], arr[hi--]);
            } 
        }
    }
};
