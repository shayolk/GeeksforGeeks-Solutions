#include <bits/stdc++.h>
using namespace std;

const int M=1e9+7;
 
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> dp0(n+1), dp1(n+1);
        dp0[1]=dp1[1]=1;
        for(int i=2; i<=n; ++i) {
            dp0[i]=(dp0[i-1]+dp1[i-1])%M;
            dp1[i]=dp0[i-1];
        }
        printf("%d\n", (dp0[n]+dp1[n])%M);
    }
 
    return 0;
}