#include <bits/stdc++.h>
using namespace std;

const int nax=1e3+15;
vector<int> dp(nax);

void init() {
    dp[0]=1;
    for(int i=0; i<nax-3; ++i) {
        if(dp[i]) {
            dp[i+3]+=dp[i];
        }
    }
    for(int i=0; i<nax-5; ++i) {
        if(dp[i]) {
            dp[i+5]+=dp[i];
        }
    }
    for(int i=0; i<nax-10; ++i) {
        if(dp[i]) {
            dp[i+10]+=dp[i];
        }
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
