class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int searchInSorted(int arr[], int N, int K) 
    {
        int lo=0, hi=N-1, mid;
        while(lo<=hi) {
            mid=lo+(hi-lo)/2;
            if(arr[mid]==K) {
                return 1;
            }
            if(arr[mid]<K) {
                lo=mid+1;
            }
            else {
                hi=mid-1;
            }
        }
        return -1;
    }
};
