//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        vector<vector<int>> ans;
        int buy=0, sell=0;
        for(int i=1; i<n; ++i) {
            if(A[i]>=A[i-1]) {
                sell=i;
            }
            else {
                if(sell>buy) ans.push_back({buy, sell});
                buy=i;
            }
        }
        if(sell>buy) ans.push_back({buy, sell});
        return ans;
    }
};
