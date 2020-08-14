#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m,x,y;
        scanf("%d%d%d", &n,&m,&x);
        unordered_map<int,bool> a;
        for(int i=0; i<n; ++i) {
            scanf("%d", &y);
            a[y]=true;
        }
        set<pair<int,int>> s;
        for(int i=0; i<m; ++i) {
            scanf("%d", &y);
            if(a[x-y]) {
                s.insert({x-y,y});
            }
        }
        int sz=(int)s.size();
        for(auto i:s) {
            printf("%d %d", i.first,i.second);
            if(--sz) printf(", ");
        }
        if(s.empty()) printf("-1");
        printf("\n");
    }
    
    return 0;
}
