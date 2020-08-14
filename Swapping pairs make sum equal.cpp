#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        scanf("%d%d", &n,&m);
        int s1=0, s2=0, x;
        unordered_set<int> a;
        for(int i=0; i<n; ++i) {
            scanf("%d", &x);
            a.insert(x);
            s1+=x;
        }
        unordered_map<int,bool> b;
        for(int i=0; i<m; ++i) {
            scanf("%d", &x);
            b[2*x]=true;
            s2+=x;
        }
        bool flag=false;
        for(int i:a) {
            if(b[s2-s1+2*i]) {
                flag=true;
                break;
            }
        }
        printf("%d\n", flag?1:-1);
    }
    
    return 0;
}
