class Solution
{
    public:
    int select(int arr[], int i, int n)
    {
        int mn=i;
        for(int j=i+1; j<n; ++j) {
            if(arr[j]<arr[mn]) {
                mn=j;
            }
        }
        return mn;
    }
     
    void selectionSort(int arr[], int n)
    {
        for(int i=0; i<n-1; ++i) {
            int j=select(arr, i, n);
            swap(&arr[i], &arr[j]);
        }
    }
};
