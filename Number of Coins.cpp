#include <bits/stdc++.h>
using namespace std;

#define INF 2e9

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int v,n;
        scanf("%d%d", &v,&n);
        vector<int> a(n), dp(v+1, INF);
        for(int& i: a) {
            scanf("%d", &i);
        }
        dp[0]=0;
        for(int i=0; i<v; ++i) {
            if(dp[i]!=INF) {
                for(int j: a) {
                    if(i+j<=v) {
                        dp[i+j]=min(dp[i+j], 1+dp[i]);
                    }
                }
            }
        }
        printf("%d\n", dp[v]==INF?-1:dp[v]);
    }
    
    return 0;
}
