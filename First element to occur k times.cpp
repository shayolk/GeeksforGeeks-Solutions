#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,k;
        scanf("%d%d", &n,&k);
        unordered_map<int,int> m;
        bool flag=true;
        int ans;
        vector<int> a(n);
        for(int i=0; i<n; ++i) {
            scanf("%d", &a[i]);
            ++m[a[i]];
        }
        for(int i=0; i<n; ++i) {
            if(m[a[i]]==k) {
                ans=a[i];
                flag=false;
                break;
            }
        }
        printf("%d\n", flag?-1:ans);
    }
    
    return 0;
}
