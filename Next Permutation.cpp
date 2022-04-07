// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int i=N-2;
        while(i>=0 && arr[i]>=arr[i+1]) --i;
        if(i>=0) {
            int j=N-1;
            while(j>=0 && arr[j]<=arr[i]) --j;
            swap(arr[i], arr[j]);
        }
        reverse(arr.begin()+i+1, arr.end());
        return arr;
    }
};
