#include <bits/stdc++.h>
using namespace std;

int main() {
    int nax=55;
    vector<long long> dp(nax);
    dp[0]=1;
    for(int i=0; i<nax-3; ++i) {
        dp[i+1]+=dp[i];
        dp[i+2]+=dp[i];
        dp[i+3]+=dp[i];
    }
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }
    
    return 0;
}
