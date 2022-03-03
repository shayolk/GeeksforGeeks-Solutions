//User function template for C++

class Solution{   
public:
    int countMinOperations(int arr[], int n) {
        int ans=0;
        while(true) {
            bool done=true;
            for(int i=0; i<n; ++i) {
                if(arr[i] && arr[i]%2) {
                    --arr[i];
                    ++ans;
                }
                if(arr[i]) done=false;
            }
            if(done) break;
            ++ans;
            for(int i=0; i<n; ++i) {
                arr[i]/=2;
            }
        }
        return ans;
    }
};
