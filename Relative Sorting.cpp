#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        scanf("%d%d", &n,&m);
        unordered_map<int,int> a;
        for(int i=0; i<n; ++i) {
            int x;
            scanf("%d", &x);
            ++a[x];
        }
        vector<int> u,v;
        for(int i=0; i<m; ++i) {
            int x;
            scanf("%d", &x);
            if(a.count(x)) {
                int y=a[x];
                while(y--) u.push_back(x);
                a[x]=0;
            }
        }
        for(auto i: a) {
            if(i.second) {
                int y=i.second;
                while(y--) v.push_back(i.first);
            }
        }
        sort(v.begin(), v.end());
        for(int i:u) printf("%d ", i);
        for(int i:v) printf("%d ", i);
        printf("\n");
    }
    
    return 0;
}
