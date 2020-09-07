#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        scanf("%d%d", &n,&m);
        vector<int> a(n), b(m), c(n+m-1);
        for(int& i: a) {
            scanf("%d", &i);
        }
        for(int& i: b) {
            scanf("%d", &i);
        }
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                c[i+j]+=a[i]*b[j];
            }
        }
        for(int i: c) {
            printf("%d ", i);
        }
        printf("\n");
    }
    
    return 0;
}
