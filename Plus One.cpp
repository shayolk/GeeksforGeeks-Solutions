//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int N) {
        reverse(arr.begin(), arr.end());
        int c=1;
        for(int i=0; i<N; ++i) {
            int here=arr[i]+c;
            arr[i]=here%10;
            c=here/10;
        }
        if(c) arr.push_back(c);
        reverse(arr.begin(), arr.end());
        return arr;
    }
};
