#include <bits/stdc++.h>
using namespace std;

int nax=1e4+5;
vector<long long> dp(nax, 9e18);

int main() {
    dp[1]=1;
    for(int i=1; i<nax-1; ++i) {
        dp[i+1]=min(dp[i+1], dp[i]+1);
        if(i*2<nax) {
            dp[2*i]=min(dp[2*i], dp[i]+1);
        }
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
