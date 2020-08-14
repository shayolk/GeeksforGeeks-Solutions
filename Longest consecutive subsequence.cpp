#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for(int& i:a) {
            scanf("%d", &i);
        }
        sort(a.begin(), a.end());
        int ans=0, now=1;
        for(int i=1; i<n; ++i) {
            if(a[i]==a[i-1]) continue;
            if(a[i]-a[i-1]==1) {
                ++now;
            }
            else {
                ans=max(ans, now);
                now=1;
            }
        }
        ans=max(ans, now);
        printf("%d\n", ans);
    }
    
    return 0;
}
