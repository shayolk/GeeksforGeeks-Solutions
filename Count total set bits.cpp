#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> dp(1001);
    for(int i=1; i<1001; ++i) {
        dp[i]=dp[i-1];
        for(int bit=0; bit<31; ++bit) {
            dp[i]+=(i&(1<<bit))!=0;
        }
    }
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
    
    return 0;
}
