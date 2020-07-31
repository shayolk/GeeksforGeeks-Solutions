#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,k;
        scanf("%d%d", &n,&k);
        vector<int> a(n);
        for(int& i:a) {
            scanf("%d", &i);
        }
        for(int i=0; i<n; i+=k) {
            for(int j=min(n-1,i+k-1); j>=i; --j) {
                printf("%d ", a[j]);
            }
        }
        printf("\n");
    }
    
    return 0;
}
