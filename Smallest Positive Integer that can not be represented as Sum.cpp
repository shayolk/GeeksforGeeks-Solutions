//User function Template for C++

class Solution
{   
public:
    long long smallestpositive(vector<long long> arr, int n)
    {
        sort(arr.begin(), arr.end());
        long long ans=1;
        int i=0;
        while(i<n && arr[i]<=ans) {
            ans+=arr[i++];
        }
        return ans;
    } 
};
