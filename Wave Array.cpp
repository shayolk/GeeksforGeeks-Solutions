class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(vector<int>& arr, int n){
        for(int i=0; i+1<n; i+=2) {
            swap(arr[i], arr[i+1]);
        }
    }
};
