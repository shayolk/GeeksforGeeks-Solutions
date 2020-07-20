#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int diff=0, x;
        scanf("%d", &x);
        int mn=x, mx=x;
        for(int i=1; i<n; ++i) {
            scanf("%d", &x);
            // if(x<mn) {
            //     mn=x;
            // }
            // else {
            //     mx=x;
            //     diff=max(diff, mx-mn);
            // }
            diff=max(diff, x-mn);
            mn=min(mn,x);
        }
        printf("%d\n", diff?diff:-1);
    }
    
    return 0;
}
