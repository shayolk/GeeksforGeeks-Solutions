#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,k;
        scanf("%d%d", &n,&k);
        vector<int> a(n);
        for(int& i:a) {
            scanf("%d", &i);
        }
        map<pair<int,int>,int> m;
        for(int i=0; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                m[{i,j}]=a[i]+a[j];
            }
        }
        set<vector<int>> ans;
        for(auto i=m.begin(); i!=m.end(); ++i) {
            auto j=i;
            for(++j; j!=m.end(); ++j) {
                int x=i->first.first, y=i->first.second, z=j->first.first, w=j->first.second;
                if(x==z || x==w || y==z || y==w) continue;
                if(a[x]+a[y]+a[z]+a[w]!=k) continue;
                vector<int> v={a[x], a[y], a[z], a[w]};
                sort(v.begin(), v.end());
                ans.insert(v);
            }
        }
        if(ans.empty()) printf("-1");
        for(auto i:ans) {
            for(int j:i) {
                printf("%d ", j);
            }
            printf("$");
        }
        printf("\n");
    }
    
    return 0;
}
