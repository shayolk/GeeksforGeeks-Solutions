#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int ans=0;
        for(int bit=0; bit<31; ++bit) {
            ans+=(n&(1<<bit))!=0;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
