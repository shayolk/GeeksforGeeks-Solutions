#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int a,b;
        scanf("%d%d", &a,&b);
        printf("%d\n", __builtin_popcount(a^b));
    }
    
    return 0;
}
