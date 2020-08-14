#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int ans=0, sum=0;
        unordered_map<int,int> m;
        m[0]=1;
        for(int i=0; i<n; ++i) {
            int x;
            scanf("%d", &x);
            sum+=x;
            ans+=m[sum];
            ++m[sum];
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
