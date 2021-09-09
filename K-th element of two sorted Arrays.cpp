class Solution{
    int partition(vector<int>& a, int lo, int hi) {
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
    
    int find(vector<int>& a, int lo, int hi, int k) {
        if(lo>hi) return -1;
        int pos=partition(a, lo, hi);
        if(pos==k) return a[pos];
        if(pos>k) return find(a, lo, pos-1, k);
        else return find(a, pos+1, hi, k);
    }
    
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        vector<int> a;
        for(int i=0; i<n; ++i) a.push_back(arr1[i]);
        for(int i=0; i<m; ++i) a.push_back(arr2[i]);
        return find(a, 0, n+m-1, k-1);
    }
};
