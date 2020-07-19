#include <bits/stdc++.h>
using namespace std;

const int nax=1e5+5, M=1e9+7;
 
int main() {
    vector<int> dp(nax);
    dp[0]=1;
    for(int i=0; i<nax-2; ++i) {
        dp[i+1]=(dp[i+1]+dp[i])%M;
        dp[i+2]=(dp[i+2]+dp[i])%M;
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
