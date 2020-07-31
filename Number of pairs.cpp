#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m,z;
        scanf("%d%d", &n,&m);
        vector<float> x(n), y(m);
        for(int i=0; i<n; ++i) {
            scanf("%d", &z);
            x[i]=log(z)/z;
        }
        for(int i=0; i<m; ++i) {
            scanf("%d", &z);
            y[i]=log(z)/z;
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        long long ans=0;
        for(long double i:x) {
            ans+=(lower_bound(y.begin(), y.end(), i)-y.begin());
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}
