class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> great(n);
        stack<int> s;
        for(int i=0; i<n; ++i) {
            while(!s.empty() && arr[s.top()]<arr[i]) {
                great[s.top()]=arr[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) {
            great[s.top()]=-1;
            s.pop();
        }
        return great;
    }
};
