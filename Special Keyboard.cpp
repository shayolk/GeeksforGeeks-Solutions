#include <bits/stdc++.h>
using namespace std;

const int nax=80;
vector<int> dp(nax);

void init() {
    for(int i=1; i<=6; ++i) {
        dp[i]=i;
    }
    for(int i=7; i<nax; ++i) {
        dp[i]=max({dp[i-1]+1, 2*dp[i-3], 3*dp[i-4], 4*dp[i-5]});
    }
}

int main() {
    init();
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
    
    return 0;
}
