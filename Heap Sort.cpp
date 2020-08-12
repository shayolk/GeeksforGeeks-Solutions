/* Main function to do heap sort. This function uses buildHeap()
   and heapify()
void heapSort(int arr[], int n)  {
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)  {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
} */
// The functions should be written in a way that array become sorted 
// in increasing order when above heapSort() is called.
// To heapify a subtree rooted with node i which is  an index in arr[]. 
// n is size of heap. This function  is used in above heapSor()
void heapify(int arr[], int n, int i)  {
    int mx=i, l=2*i+1, r=2*i+2;
    if(l<n && arr[l]>arr[mx]) {
        mx=l;
    }
    if(r<n && arr[r]>arr[mx]) {
        mx=r;
    }
    if(mx!=i) {
        swap(arr[i], arr[mx]);
        heapify(arr,n,mx);
    }
}

// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n)  {
    for(int i=n/2-1; i>=0; --i) {
        heapify(arr,n,i);
    }
}
