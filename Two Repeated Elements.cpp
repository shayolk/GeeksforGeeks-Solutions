//User function template for C++

class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int N) {
        vector<int> ans;
        for(int i=0; i<N+2; ++i) {
            if(arr[abs(arr[i])]<0) ans.push_back(abs(arr[i]));
            else arr[abs(arr[i])]*=-1;
        }
        return ans;
    }
};
