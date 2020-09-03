#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,k;
        scanf("%d%d", &n,&k);
        vector<int> a(n);
        for(int i=0; i<k; ++i) {
            int x,y;
            scanf("%d%d", &x,&y);
            ++a[x];
        }
        int ans=0;
        for(int i: a) {
            ans+=i;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
