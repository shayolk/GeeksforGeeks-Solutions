#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int m;
        scanf("%d", &m);
        vector<int> a(m);
        for(int& i: a) {
            scanf("%d", &i);
        }
        int n;
        scanf("%d", &n);
        vector<long long> dp(n+1);
        dp[0]=1;
        for(int i: a) {
            for(int j=i; j<=n; ++j) {
                dp[j]+=dp[j-i];
            }
        }
        printf("%lld\n", dp[n]);
    }
 
    return 0;
}