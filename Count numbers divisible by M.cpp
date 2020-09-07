#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int a,b,m;
        scanf("%d%d%d", &a,&b,&m);
        printf("%d\n", b/m-(a-1)/m);
    }
    
    return 0;
}
