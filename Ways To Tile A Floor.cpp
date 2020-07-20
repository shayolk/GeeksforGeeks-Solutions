#include <bits/stdc++.h>
using namespace std;

const int nax=71;
vector<long> dp(nax);

void init() {
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<nax; ++i) {
        dp[i]+=dp[i-1];
        dp[i]+=dp[i-2];
    }
}
 
int main() {
    init();
    int t;
    scanf("%d", &t);
    while(t--) {
        int w;
        scanf("%d", &w);
        printf("%ld\n", dp[w]);
    }
 
    return 0;
}
