//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        vector<int> ans{1}, tmp;
        for(int i=2; i<=N; ++i) {
            long long car=0;
            tmp=ans;
            ans.clear();
            for(int now: tmp) {
                long long here=i*now+car;
                ans.push_back(here%10);
                car=here/10;
            }
            while(car) {
                ans.push_back(car%10);
                car/=10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
