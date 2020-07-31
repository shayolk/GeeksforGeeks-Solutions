#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        scanf("%d", &n);
        vector<int> a(n);
        for(int& i:a) {
            scanf("%d", &i);
        }
        scanf("%d", &m);
        sort(a.begin(), a.end());
        int ans=2e9;
        for(int i=0; i+m-1<n; ++i) {
            ans=min(ans,a[i+m-1]-a[i]);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
