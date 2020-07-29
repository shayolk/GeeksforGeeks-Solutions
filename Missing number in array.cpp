#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int ans=n,x;
        for(int i=1; i<n; ++i) {
            ans^=i;
            scanf("%d", &x);
            ans^=x;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
