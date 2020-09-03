#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,k;
        scanf("%d%d", &n,&k);
        vector<int> a(n);
        for(int& i: a) {
            scanf("%d", &i);
        }
        map<int,int> m;
        ++m[a[n-1]];
        int ans=0;
        for(int i=n-2; i>=0; --i) {
            ans+=m[k-a[i]];
            ++m[a[i]];
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
