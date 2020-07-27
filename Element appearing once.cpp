#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,x,ans=0;
        scanf("%d", &n);
        while(n--) {
            scanf("%d", &x);
            ans^=x;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
