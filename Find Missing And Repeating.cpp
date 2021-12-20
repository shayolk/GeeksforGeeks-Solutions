class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int x=0;
        for(int i=0; i<n; ++i) {
            x^=arr[i];
        }
        for(int i=1; i<=n; ++i) {
            x^=i;
        }
        int bit;
        for(bit=0; bit<31; ++bit) {
            if(x & (1<<bit)) {
                break;
            }
        }
        int one=0, zero=0;
        for(int i=0; i<n; ++i) {
            if(arr[i] & (1<<bit)) {
                one^=arr[i];
            }
            else {
                zero^=arr[i];
            }
        }
        for(int i=1; i<=n; ++i) {
            if(i & (1<<bit)) {
                one^=i;
            }
            else {
                zero^=i;
            }
        }
        int *ans=new int[2];
        ans[0]=one;
        ans[1]=zero;
        for(int i=0; i<n; ++i) {
            if(arr[i]==one) {
                return ans;
            }
        }
        ans[0]=zero;
        ans[1]=one;
        return ans;
    }
};
