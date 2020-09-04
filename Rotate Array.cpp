#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,d;
        scanf("%d%d", &n,&d);
        vector<int> a(n);
        for(int i=0; i<n; ++i) {
            scanf("%d", &a[(i-d+n)%n]);
        }
        for(int i=0; i<n; ++i) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    
    return 0;
}
