#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        scanf("%d%d", &n,&m);
        vector<long long> a(n);
        for(long long& i: a) {
            scanf("%lld", &i);
        }
        set<long long> s;
        for(int i=0; i<m; ++i) {
            long long x;
            scanf("%lld", &x);
            s.insert(x);
        }
        for(long long i: a) {
            if(!s.count(i)) {
                printf("%lld ", i);
            }
        }
        printf("\n");
    }
    
    return 0;
}
