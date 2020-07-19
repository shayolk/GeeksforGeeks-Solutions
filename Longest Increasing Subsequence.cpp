#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int t;
    scanf("%lld", &t);
    while(t--) {
        int n;
        scanf("%lld", &n);
        vector<int> a(n);
        for(int& i: a) {
            scanf("%lld", &i);
        }
        vector<int> dp(n, 1);
        for(int i=1; i<n; ++i) {
            for(int j=0; j<i; ++j) {
                if(a[j]<a[i]) {
                    dp[i]=max(dp[i], 1+dp[j]);
                }
            }
        }
        printf("%lld \n", *max_element(dp.begin(), dp.end()));
    }
}