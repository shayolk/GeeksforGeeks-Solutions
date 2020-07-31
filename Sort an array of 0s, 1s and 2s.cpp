#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,x;
        scanf("%d", &n);
        vector<int> a(3);
        while(n--) {
            scanf("%d", &x);
            ++a[x];
        }
        for(int i=0; i<3; ++i) {
            for(int j=0; j<a[i]; ++j) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    
    return 0;
}
