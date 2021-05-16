class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int s1=m-l+2, s2=r-m+1;
        int a1[s1], a2[s2];
        a1[s1-1]=a2[s2-1]=1e9+5;
        for(int i=0; i<s1-1; ++i) {
            a1[i]=arr[l+i];
        }
        for(int i=0; i<s2-1; ++i) {
            a2[i]=arr[m+1+i];
        }
        int i=0, j=0, k=l;
        while(k<=r) {
            if(a1[i]<a2[j]) {
                arr[k++]=a1[i++];
            }
            else {
                arr[k++]=a2[j++];
            }
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r) {
            return;
        }
        int mid=l+(r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
};
