#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        long long sum=0,x;
        vector<long long> pref={0};
        for(int i=0; i<n; ++i) {
            scanf("%lld", &x);
            sum+=x;
            pref.push_back(pref.back()+x);
        }
        int flag=true;
        for(int i=1; i<=n; ++i) {
            if(pref[i-1]==sum-pref[i]) {
                flag=false;
                printf("%d\n", i);
                break;
            }
        }
        if(flag) printf("-1\n");
    }
    
    return 0;
}
