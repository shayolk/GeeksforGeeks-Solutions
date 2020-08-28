#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int k,n;
        scanf("%d%d", &k,&n);
        vector<int> a(n);
        for(int& i: a) {
            scanf("%d", &i);
        }
        int mn=a[0], mx=a[0];
        for(int i=1; i<n; ++i) {
            mn=min(mn, a[i]);
            mx=max(mx, a[i]);
        }
        int dif=mx-mn;
        float avg=(mn+mx)/2;
        mn=2e9, mx=-2e9;
        for(int i=0; i<n; ++i) {
            if(a[i]<avg) a[i]+=k;
            else a[i]-=k;
            mn=min(mn, a[i]);
            mx=max(mx, a[i]);
        }
        dif=min(dif, mx-mn);
        printf("%d\n", dif);
    }
    
    return 0;
}
