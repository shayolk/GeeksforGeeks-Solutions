class Solution{
    int nextGap(int gap) {
        if(gap<=1) {
            return 0;
        }
        return gap/2+gap%2;
    }
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int m, int n) 
        {
            int gap=nextGap(m+n+1);
            while(gap) {
                for(int i=0; i+gap<m+n; ++i) {
                    int j=i+gap;
                    if(i<m && j<m) {
                        if(arr1[i]>arr1[j]) swap(arr1[i], arr1[j]);
                    }
                    else if(i<m && j>=m) {
                        if(arr1[i]>arr2[j-m]) swap(arr1[i], arr2[j-m]);
                    }
                    else {
                        if(arr2[i-m]>arr2[j-m]) swap(arr2[i-m], arr2[j-m]);
                    }
                }
                gap=nextGap(gap);
            }
        } 
};
