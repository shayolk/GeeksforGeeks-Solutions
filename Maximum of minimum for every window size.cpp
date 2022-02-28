class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        int left[n], right[n];
        stack<int> s;
        for(int i=0; i<n; ++i) {
            while(!s.empty() && arr[s.top()]>=arr[i]) {
                s.pop();
            }
            if(s.empty()) left[i]=-1;
            else left[i]=s.top();
            s.push(i);
        }
        s=stack<int>();
        for(int i=n-1; i>=0; --i) {
            while(!s.empty() && arr[s.top()]>=arr[i]) {
                s.pop();
            }
            if(s.empty()) right[i]=n;
            else right[i]=s.top();
            s.push(i);
        }
        vector<int> ans(n);
        for(int i=0; i<n; ++i) {
            int len=right[i]-left[i]-1;
            ans[len-1]=max(ans[len-1], arr[i]);
        }
        for(int i=n-2; i>=0; --i) {
            ans[i]=max(ans[i], ans[i+1]);
        }
        return ans;
    }
};
