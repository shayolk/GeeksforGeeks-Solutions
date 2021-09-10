// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution{
    const int INF=1e9+5;
  public:
    int threeSumClosest(vector<int> arr, int target) {
        sort(arr.begin(), arr.end());
        int n=arr.size();
        vector<int> less{INF}, more{INF};
        for(int k=0; k<n; ++k) {
            int i=0, j=n-1;
            while(i<j) {
                int sum=arr[i]+arr[j]+arr[k];
                if(i!=k && j!=k && sum==target) return sum;
                if(sum<target) {
                    if(i!=k && j!=k) less.push_back(target-sum);
                    ++i;
                }
                else {
                    if(i!=k && j!=k) more.push_back(sum-target);
                    --j;
                }
            }
        }
        sort(less.begin(), less.end());
        sort(more.begin(), more.end());
        return more[0]<=less[0]?target+more[0]:target-less[0];
    }
};
