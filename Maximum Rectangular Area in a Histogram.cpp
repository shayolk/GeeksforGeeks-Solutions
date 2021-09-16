class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        long long ans=0, ls, rs, h;
        stack<int> s;
        for(int i=0; i<=n; ++i) {
            while(!s.empty() && (i==n || arr[i]<=arr[s.top()])) {
                h=arr[s.top()];
                s.pop();
                ls=s.empty()?-1:s.top();
                rs=i;
                ans=max(ans, h*(rs-ls-1));
            }
            s.push(i);
        }
        return ans;
    }
};
