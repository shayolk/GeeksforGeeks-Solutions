class Solution
{
    public:
    void insert(int arr[], int i)
    {
        int j=0;
        while(j<i && arr[j]<arr[i]) {
            ++j;
        }
        int x=arr[i];
        for(int k=i; k>j; --k) {
            arr[k]=arr[k-1];
        }
        arr[j]=x;
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        for(int i=1; i<n; ++i) {
            insert(arr, i);
        }
    }
};
