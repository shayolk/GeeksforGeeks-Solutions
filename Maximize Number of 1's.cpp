class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        int ans=0, cnt=0, mm=0, st=-1, ed=-1;
        for(int i=0; i<n; ++i) {
            if(arr[i]) {
                ++cnt;
            }
            else {
                if(mm<m) {
                    ++mm;
                    ++cnt;
                }
                else {
                    ++st;
                    ++ed;
                    while(st<n && arr[st]) {
                        ++st;
                        --cnt;
                    }
                }
            }
            ans=max(ans, cnt);
        }
        return ans;
    }  
};
