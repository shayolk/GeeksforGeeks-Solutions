#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> isp(32, true);
    isp[0]=isp[1]=false;
    for(int i=4; i<32; i+=2) {
        isp[i]=false;
    }
    for(int i=3; i*i<32; ++i) {
        if(isp[i]) {
            for(int j=i*i; j<32; j+=i) {
                isp[j]=false;
            }
        }
    }
    vector<int> dp(100005);
    for(int i=1; i<100005; ++i) {
        int cnt=0;
        for(int bit=0; bit<31; ++bit) {
            cnt+=(i&(1<<bit))!=0;
        }
        dp[i]=dp[i-1]+isp[cnt];
    }
    
    int t;
    scanf("%d", &t);
    while(t--) {
        int l,r;
        scanf("%d%d", &l,&r);
        printf("%d\n", dp[r]-dp[l-1]);
    }
    
    return 0;
}
