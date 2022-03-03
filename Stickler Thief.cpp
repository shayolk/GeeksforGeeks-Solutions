class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        int prev1=arr[0];
        int prev2=0;
        for(int i=1; i<n; ++i) {
            int curr=max(prev1, prev2+arr[i]);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};
