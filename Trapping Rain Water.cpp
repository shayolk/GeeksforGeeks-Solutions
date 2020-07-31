#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n), pref(n), suf(n);
        for(int& i:a) {
            scanf("%d", &i);
        }
        pref[0]=a[0];
        for(int i=1; i<n; ++i) {
            pref[i]=max(a[i], pref[i-1]);
        }
        suf[n-1]=a[n-1];
        for(int i=n-2; i>=0; --i) {
            suf[i]=max(a[i], suf[i+1]);
        }
        long long ans=0;
        for(int i=1; i<n-1; ++i) {
            ans+=min(pref[i],suf[i])-a[i];
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
