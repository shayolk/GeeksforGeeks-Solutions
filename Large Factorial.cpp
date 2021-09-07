//User function template for C++


class Solution{
    const int M=1e9+7;
public:
    vector<long long> factorial(vector<long long> a, int n) {
        long long mx=*max_element(a.begin(), a.end());
        long long fact[mx+1];
        fact[0]=1;
        for(long long i=1; i<=mx; ++i) {
            fact[i]=(i*fact[i-1])%M;
        }
        for(auto& i: a) {
            i=fact[i];
        }
        return a;
    }
};
