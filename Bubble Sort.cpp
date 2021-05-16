//User function Template for C++

class Solution
{
    public:
    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        for(int j=n; j>0; --j) {
            for(int i=0; i<j-1; ++i) {
                if(arr[i]>arr[i+1]) {
                    swap(&arr[i], &arr[i+1]);
                }
            }
        }
    }
};
