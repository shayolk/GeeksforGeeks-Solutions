#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for(int& i: a) {
            scanf("%d", &i);
        }
        vector<int> dp(n);
        dp[0]=a[0];
        for(int i=1; i<n; ++i) {
            for(int j=0; j<i; ++j) {
                if(a[i]>a[j]) {
                    dp[i]=max(dp[i],dp[j]);
                }
            }
            dp[i]+=a[i];
        }
        printf("%d\n", *max_element(dp.begin(), dp.end()));
    }
 
    return 0;
}