//User function template for C++

class Solution{
    int partition(int a[], int lo, int hi) {
        int pos=lo+rand()%(hi-lo+1);
        swap(a[pos], a[hi]);
        int i=lo;
        for(int j=lo; j<hi; ++j) {
            if(a[j]<=a[hi]) {
                swap(a[i++], a[j]);
            }
        }
        swap(a[i], a[hi]);
        return i;
    }
    
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        if(l>r) return -1;
        int pos=partition(arr, l, r);
        if(pos==k-1) return arr[pos];
        if(pos>k-1) return kthSmallest(arr, l, pos-1, k);
        return kthSmallest(arr, pos+1, r, k);
    }
};
