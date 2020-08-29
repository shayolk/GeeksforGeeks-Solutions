#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,k;
        scanf("%d%d", &n,&k);
        vector<bool> eat(n+1);
        for(int i=0; i<k; ++i) {
            int x;
            scanf("%d", &x);
            if(!eat[x]) {
                for(int j=x; j<=n; j+=x) {
                    eat[j]=true;
                }
            }
        }
        printf("%d\n", count(eat.begin(), eat.end(), false)-1);
    }
    
    return 0;
}
