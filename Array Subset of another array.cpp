#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        scanf("%d%d", &n,&m);
        unordered_map<int,bool> a;
        for(int i=0; i<n; ++i) {
            int x;
            scanf("%d", &x);
            a[x]=true;
        }
        bool flag=true;
        for(int i=0; i<m; ++i) {
            int x;
            scanf("%d", &x);
            flag&=a[x];
        }
        puts(flag?"Yes":"No");
    }
    
    return 0;
}
